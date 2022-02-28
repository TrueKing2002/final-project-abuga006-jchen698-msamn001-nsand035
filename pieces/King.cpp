#include "ChessPiece.hpp"

class King : public ChessPiece {
    string getPiece() {
        if (white) return "♚";
        else return "♔";
    }
    
    bool UpDown(ChessPiece** board, int dest, int location) {
		// white pieces
		if (white) {
			//check above location to see if there is a piece there
			if (board[location + 1] != nullptr) {
				// check if the piece above is the same color, if so return false
				if (board[location + 1]->white) {
					return false;
				}
				// piece is not our color, and we can capture it
				// set the location to null, so we can move there
				board[location + 1] == nullptr;
				return true;
			}
			// there is no piece above so we can move there
			else if (dest == location + 1) {
				return true;
			}

			// check location below to see if there is a piece there
			if (board[location - 1] != nullptr) {
				// check if the piece below is the same color, if so return false
				if (board[location - 1]->white) {
					return false;
				}
				// piece is not our color, and we can capture it
				// set the location to null, so we can move there
				board[location - 1] == nullptr;
				return true;
			}
			// there is no piece above so we can move there
			else if (dest == location + 1) {
				return true;
			}
		}
		// black pieces (similar to above)
		else {
			// check above
			if (board[location + 1] != nullptr) {
				// check if the piece above is white, if so capture it
				if (board[location + 1]->white) {
					board[location + 1] == nullptr;
					return true;
				}
				// piece is black so cant move there, return false
				return false;
			}
			// there is no piece above so we can move there
			else if (dest == location + 1) {
				return true;
			}

			// check below
			if (board[location - 1] != nullptr) {
				// check if the piece below is white, if so capture it
				if (board[location + 1]->white) {
					board[location + 1] == nullptr;
					return true;
				}
				// piece is black so cant move there, return false
				return false;
			}
			// there is no piece below so we can move there
			else if (dest == location - 1) {
				return true;
			}
		}
		return false;
	}

	bool canMove(ChessPiece** board, int dest, int location) {
		dest = trans(dest);
		if (UpDown(board, dest, location)) {
			return true;
		}
		return false;
	}
};
