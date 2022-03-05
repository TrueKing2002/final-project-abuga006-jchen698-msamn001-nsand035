#include "ChessPiece.hpp"

class Knight : public ChessPiece {
public:
    Knight() {id = 2;}

    string getPiece() {
        if (white) return "♞";
        else return "♘";
    }
    
    bool canMove(ChessPiece** board, int dest) {
	dest = trans(dest);

	if (board[dest] != nullptr) {
	    if (white) {
		if (board[dest]->white) {
		    return false;
		}
	    }
	    if (!white) {
		if (!board[dest]->white) {
		    return false;
		}
	    }
	}
	
	int inColumn;
	int inRow;
	int column;
	int row;

	if (location % 8 == 0) { //If initial on last column
	     inColumn = 8; //Will be in column h
	     inRow = location / 8; //Don't need to add 1 since it is divisible by 8
	}
	else { //General coordinates of initial
	     inColumn = location % 8; //All other columns except h
	     inRow = location / 8 + 1; //All rows when not in column h
	}

	if (dest % 8 == 0) { //If destination on last column
	     column = 8; //Will be in column h
	     row = dest / 8; //Don't need to add 1 since it is divisible by 8;
	}
	else { //General coordinates of destination
	     column = dest % 8; //All other columns except h
	     row = dest / 8 + 1; //All rows when not in column h
	}
	
	if (column - inColumn == 1 || column - inColumn == -1) {
	    if (row - inRow == 2 || row - inRow == -2) {
		return true;
	    }
	}
	
	if (column - inColumn == 2 || column - inColumn == -2) {
	    if (row - inRow == 1 || row - inRow == -1) {
		return true;
	    }
	}
	
	return false;
    }
};
