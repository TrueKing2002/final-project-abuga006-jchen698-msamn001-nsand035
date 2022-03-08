#include "ChessPiece.hpp"

class Queen : public ChessPiece {
public:
    Queen() {id = 5;}

    string getPiece() {
        if (white) return "♛";
        else return "♕";
    }
    
private:       
    bool validDiagonal(ChessPiece** board, int dest) { // By Justin Chen

        int inColumn;
        if (location % 8 == 0) inColumn = 8; 
        else inColumn = trans(location % 8);
        int inRow = location / 8 + 1;

        int column;
        if (dest % 8 == 0) column = 8;
        else column = trans(dest % 8);
        int row = dest / 8 + 1;

        if (row - inRow == 0 || column - inColumn == 0) return false; //Makes sure that the bishop trying to move to its own coordinate returns false (0-0=0 would pass validCheck)

        int validCheck = abs(row - inRow) - abs(column - inColumn); //Checks difference in row and column between initial and destination positions


        if (validCheck == 0) { //Check that the destination is a location diagonal to the initial position
            int diagonalPath;
            int collisionCheck = location;

            if (row - inRow > 0) { //If the destination is above the initial position
                if (column - inColumn > 0) { //If destination is to the right of bishop
                    diagonalPath = 7; //Index would iterate up right diagonally
                }
                if (column - inColumn < 0) { //If destination is to the left of bishop
                    diagonalPath = 9; //Index would iterate up left diagonally
                }
            }
            if(row - inRow < 0) { //If destination is below the initial position
                if (column - inColumn > 0) { //If destination is to the right of bishop
                    diagonalPath = -9; //Index would iterate down right diagonally
                }
                if (column - inColumn < 0) { //If destination is to the left of bishop
                    diagonalPath = -7; //Index would iterate down left diagonally
                }
            }
            collisionCheck += diagonalPath; //Iterate to collisionCheck to next immediate diagonal from initial
            while (collisionCheck != dest) { //Continue checking diagonally until reaching the destination position
                if (board[collisionCheck] != nullptr) { //Check to make sure that there is nothing along the diagonal path from the initial position to the destination
                    return false; //Invalid move since there is a piece along the diagonal path
                }
                collisionCheck += diagonalPath; //Iterate to next diagonal position
            }
            return true; //This is a valid move since there were no obstacles found along the diagonal path between the bishop and the destination
        }

        return false; //Invalid move since it is not along a diagonal path
    }

    bool validColumn(ChessPiece** board, int dest) { // By Megan Samn
        for (int i = 1; i < 9; ++i) {
        
            if (location - (8*i) > 0 && location - (8*i) >= dest) { //move Rook down
                if (board[location - (8*i)] != nullptr && location - (8*i) > dest) //if there is a piece before we reach destination
                    return false;

                else if (location - (8*i) == dest)  //reached valid destination
                    return true;
            }
            if (location + (8*i) < 64 && location + (8*i) <= dest) { //move Rook up
                if (board[location + (8*i)] != nullptr && location + (8*i) < dest) 
                    return false;

                else if (location + (8*i) == dest) 
                    return true;
            }
        }
        return false;
    }
    
    bool validRow(ChessPiece** board, int dest) { // By Megan Samn
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
                if (board[(location - i)] != nullptr && location - i > dest)  //if there is a piece before we reach destination
                    return false;

                else if ((location - i) == dest)  //reached valid destination
                    return true;
            }
            if ( (location + i) <= rightEdge ) { //move Rook right
                if (board[(location + i)] != nullptr && location + i < dest) 
                    return false;

                else if ((location + i) == dest) 
                    return true;
            }
        }
        
        return false;
    }

public:
    bool canMove(ChessPiece** board, int dest) {
        dest = trans(dest);

        if (board[dest] && ((white && board[dest]->white) || (!white && !board[dest]->white)))
            return false;

        if (validDiagonal(board, dest) || validRow(board, dest) || validColumn(board, dest)) 
            return true;

        return false;
    }
};
