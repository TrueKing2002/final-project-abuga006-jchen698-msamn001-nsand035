#include "ChessPiece.hpp"

class Rook : public ChessPiece {
public:
    Rook() {id = 4;}

    string getPiece() {
        if (white) return "♜";
        else return "♖";
    }
    
    bool validColumn(ChessPiece** board, int dest, int location) {
    	for (int i = 1; i < 9; ++i) {
	    
	    if (location - (8*i) > 0 && location - (8*i) >= dest) { //move Rook down
                if (board[location - (8*i)] != nullptr && location - (8*i) > dest) { //if there is a piece before we reach destination
			return false;
                }
                else if (location - (8*i) == dest) { //reached valid destination
                        return true;
                }
            }
	    if (location + (8*i) < 64 && location + (8*i) <= dest) { //move Rook up
                if (board[location + (8*i)] != nullptr && location + (8*i) < dest) { 
			return false;
                }
                else if (location + (8*i) == dest) { 
                        return true;
                }
            }
		    	
        }
        return false;
    }
	
    bool validRow(ChessPiece** board, int dest, int location) {
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
    
    for (int i = 1; i < 9; ++i) {
        if ( (location - i) >= leftEdge ) { //move Rook left
             if (board[(location - i)] != nullptr && location - i > dest) { //if there is a piece before we reach destination
		return false;
             }
             else if ((location - i) == dest) { //reached valid destination
                 return true;
             }
         }
 	if ( (location + i) <= rightEdge ) { //move Rook right
             if (board[(location + i)] != nullptr && location + i < dest) { 
		return false;
             }
             else if ((location + i) == dest) { 
                 return true;
             }
         }
    }
    
    return false;
    }

    bool canMove(ChessPiece** board, int dest) {
	dest = trans(dest);
	if (validRow(board, dest, location) || validColumn(board, dest, location)) {
        // if dest is in same row or in same column and has a clear path
        	if (board[dest] == nullptr) { //if empty spot, valid
        		return true;
		}
		else {
                	// if dest != nullptr, there's a piece there... if that piece's color isnt ours, return true, else return false
        		if ( (!board[dest]->white && board[location]->white) || (board[dest]->white && !board[location]->white) ) {
				return true;
			}
		}
	}
        return false;
    }
};
