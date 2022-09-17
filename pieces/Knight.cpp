#include "ChessPiece.hpp"

class Knight : public ChessPiece {
public:
    Knight() {id = 2;}

    string getPiece() {
        if (white) return "♞";
        else return "♘";
    }
    
    bool canMove(ChessPiece** board, int dest) { // By Justin Chen
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
	}
	else { //General coordinates of initial
	     inColumn = trans(location % 8); //All other columns except h
	}
	inRow = location / 8 + 1; //All rows when not in column h

	if (dest % 8 == 0) { //If destination on last column
	     column = 8; //Will be in column h
	}
	else { //General coordinates of destination
	     column = trans(dest % 8); //All other columns except h
	}
	row = dest / 8 + 1; //All rows when not in column h
	
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
