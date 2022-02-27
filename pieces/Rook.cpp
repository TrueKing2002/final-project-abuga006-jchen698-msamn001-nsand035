#include "ChessPiece.hpp"

class Rook : public ChessPiece {
public:
    Rook() {id = 4;}

    string getPiece() {
        if (white) return "♜";
        else return "♖";
    }
    
    bool inColumn(int dest, int location) {
    	for (int i = 0; i < 8; ++i) {
		if ( (location - (8*i) > 0) && (dest == location - (8*i)) || (location + (8*i) < 64) && (dest == location + (8*i)) ) {
            	// if (dest is below location and more than 0 || dest is above location and less than 64)
        		return true;
        	}
        }
        return false;
    }
	
    bool inRow(int dest, int location) {
    int leftEdge = 0;
    int rightEdge = 0;
    
    for (int i = 0; i < 8; ++i) {
        if ((location - i) % 8 == 0) {
            leftEdge = location - i;
        }
        if ((location + i) % 8 == 7) {
            rightEdge = location + i;
        }
    }
    
    for (int i = 0; i < 8; ++i) {
        if (((dest == (location - i)) && (location - i) >= leftEdge) || ((dest == (location + i)) && (location + i) <= rightEdge)) {
        // if (dest is right of left edge || dest is left of right edge)    
	    return true;
        }
    }
    
    return false;
    }

    bool canMove(ChessPiece** board, int dest) {
	dest = trans(dest);
	if (inRow(dest, location) || inColumn(dest, location)) {
        // if dest in same row or in same column, its valid
        	if (board[dest] == nullptr) {
        		// if dest == nullptr, its valid
        		return true;
		}
		else {
                	// if dest != nullptr, there's a piece there... if that piece's color isnt ours, return true, else return false
        		if ( (!board[dest]->white && board[location]->white) || (board[dest]->white && !board[location]->white) ) {
			//if (!board[dest]->white && board[location]->white) || (board[dest]->white && !board[location]->white)
				return true;
			}
		}
	}
        return false;
    }
};
