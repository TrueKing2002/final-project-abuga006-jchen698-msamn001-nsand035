#include "ChessPiece.hpp"

class King : public ChessPiece {
    string getPiece() {
        if (white) return "♚";
        else return "♔";
    }

	bool UpDown(ChessPiece** board, int dest, int location) {
		if (board[location + 8] != nullptr) {
			// if there is a piece, return false
			return false;
		}
		else if (dest == location + 8) {
			return true;
		}

		if (board[location - 8] != nullptr) {
			return false;
		}
		else if (dest == location - 8) {
			return true;
		}
		return false;
	}
    
    bool LeftRight(ChessPiece** board, int dest, int location) {
		// white pieces
		if (white) {
			//check location to the right to see if there is a piece there
			if (board[location + 1] != nullptr) {
				// if there is a piece, return false
				return false;
			}
			// there is no piece above so we can move there
			else if (dest == location + 1) {
				return true;
			}

			// check location to the left to see if there is a piece there
			if (board[location - 1] != nullptr) {
				// if there is a piece, return false
				return false;
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

	bool Diagonal(ChessPiece** board, int dest, int location) {
		// up right
		if (board[location + 9] != nullptr) {
			return false;
		}
		else {
			return true;
		}

		// up left
		if (board[location + 7] != nullptr) {
			return false;
		}
		else {
			return true;
		}

		// down right
		if (board[location - 7] != nullptr) {
			return false;
		}
		else {
			return true;
		}

		// down left
		if (board[location - 9] != nullptr) {
			return false;
		}
		else {
			return true;
		}
	}

	bool canMove(ChessPiece** board, int dest, int location) {
		dest = trans(dest);

		// if the square is not on the board, return false
		if (dest < 1 || dest > 64) {
			return false;
		}

		if (UpDown(board, dest, location)) || LeftRight(board, dest, location) || Diagonal(board, dest, location) {
			return true;
		}
		return false;
	}
};
