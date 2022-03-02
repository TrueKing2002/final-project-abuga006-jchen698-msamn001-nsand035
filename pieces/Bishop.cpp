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

	if (row - inRow == 0 && column - inColumn == 0) {return false;} //Makes sure that the bishop trying to move to its own coordinate returns false (0-0=0 would pass validCheck)

	int validCheck = (row - inRow) - (column - inColumn); //Checks difference in row and column between initial and destination positions
	
	int collisionCheck = location;
	int diagonalPath;


	if (validCheck == 0) { //Check that the destination is a location diagonal to the initial position
	    if (row - inRow > 0) { //If the destination is above the initial position
		if (column - inColumn > 0) { //If destination is to the right of bishop
		    diagonalPath = 9; //Index would iterate up right diagonally
		}
		if (column - inColumn < 0) { //If destination is to the left of bishop
		    diagonalPath = 7; //Index would iterate up left diagonally
		}
	    }
	    if(row - inRow < 0) { //If destination is below the initial position
		if (column - inColumn > 0) { //If destination is to the right of bishop
		    diagonalPath = -7; //Index would iterate down right diagonally
		}
		if (column - inColumn < 0) { //If destination is to the left of bishop
		    diagonalPath = -9; //Index would iterate down left diagonally
		}
	    }
	    collisionCheck += diagonalPath; //Iterate to collisionCheck to next immediate diagonal from initial
	    while (collisionCheck != dest) { //Continue checking diagonally until reaching the destination position
		if (board[collisionChkeck] != nullptr) { //Check to make sure that there is nothing along the diagonal path from the initial position to the destination
		    return false; //Invalid move since there is a piece along the diagonal path
		}
		collisionCheck += diagonalPath; //Iterate to next diagonal position
	    }
	    return true; //This is a valid move since there were no obstacles found along the diagonal path between the bishop and the destination
	}	

	return false; //Invalid move since it is not along a diagonal path
    }

};
