#include "ChessPiece.hpp"

class Bishop : public ChessPiece {
public:
    Bishop() {id = 3;}

    string getPiece() {
        if (white) return "♝";
        else return "♗";
    }
    
    bool canMove(ChessPiece** board, int dest) {
	dest = trans(dest);

	if (board[dest] != nullptr) {
	    if (white) {
		if (board[dest]->white) {
		    return false;
		}
	    }
	    if (black) {
		if (board[dest]->black) {
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

	int validCheck = (row - inRow) - (column - inColumn); //Checks difference in row and column between initial and destination positions

	if (validCheck == 0) {
	    return true;
	}

	return false;
    }

};
