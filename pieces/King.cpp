#include "ChessPiece.hpp"

class King : public ChessPiece {
public:
    King() {id = 6;}

    string getPiece() {
        if (white) return "♚";
        else return "♔";
    }
    
    bool UpDown(ChessPiece** board, int dest, int location) {
        // check above and below (+8/-8)
        if ((dest == location + 8) || (dest == location - 8)) {
	    return true;
	}
	return false;
    }

    bool LeftRight(ChessPiece** board, int dest, int location) {
        // check right and left (+1/-1)
        if ((dest == location + 1 && location % 8 != 7) || (dest == location - 1 && location % 8 != 0)) {
			return true;
		}
		return false;
    }   

    bool Diagonal(ChessPiece** board, int dest, int location) { 
        // right side
        if (location % 8 != 7) {
	    // up right
            if (dest == location + 9) {
	        return true;
	    }
            
            // down right
            if (dest == location - 7) {
		return true;
	    }
        }

        // left side
        if (location % 8 != 0) {
            // up left
            if (dest == location + 7) {
		return true;
	    }

            // down left
            if (dest == location - 9) {
		return true;
	    }
        }
    return false;
    }

    bool canMove(ChessPiece** board, int dest) {
        dest = trans(dest);

	if (board[dest] != nullptr) {
	    if (white && board[dest]->white) {
	        return false;
	    }
	    if (!white && !board[dest]->white) {
		return false;
	    }
	}

	if (UpDown(board, dest, location) || LeftRight(board, dest, location) || Diagonal(board, dest, location)) {
		return true;
	}
	return false;
    }    								
};
