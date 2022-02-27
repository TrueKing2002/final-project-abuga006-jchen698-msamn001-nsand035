#include "ChessPiece.hpp"

class Rook : public ChessPiece {
public:
    Rook() {id = 4;}

    string getPiece() {
        if (white) return "♜";
        else return "♖";
    }
    
    bool validColumn(ChessPiece** board, int dest, int location) {
    	for (int i = 0; i < 8; ++i) {
	    if (location - (8*i) > 0) { //checking below location
            	if (board[location - (8*i)] != nullptr) { //if there is a piece in the way, can't pass through a piece
                	return false;
            	}
            	else if (dest == location - (8*i)) { //found valid destination
                	return true;
            	}
            }
            if (location + (8*i) < 64) { //checking above location
                if (board[location + (8*i)] != nullptr) { //if there is a piece in the way, can't pass through a piece
                        return false;
                }
                else if (dest == location + (8*i)) { //found valid destination
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
    
    for (int i = 0; i < 8; ++i) {
        if ( (location - i) >= leftEdge ) { //checking left side
            if (board[(location - i)] != nullptr) { //if there is a piece in the way, can't pass through a piece
                return false;
            }
            else if (dest == (location - i)) { //found valid destination
                return true;
            }
        }
	if ( (location + i) <= rightEdge ) { //checking right side
            if (board[(location + i)] != nullptr) { //if there is a piece in the way, can't pass through a piece
                return false;
            }
            else if (dest == (location + i)) { //found valid destination
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
