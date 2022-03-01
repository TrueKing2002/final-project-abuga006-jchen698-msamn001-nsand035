#include "ChessPiece.hpp"

class Pawn : public ChessPiece {
public:
    Pawn() {id = 1;}

    string getPiece() {
        if (white) return "♟";
        else return "♙";
    }
    
    bool canMove(ChessPiece** board, int dest) { 
        dest = trans(dest);
        if (white) {    // For a white pawn:
            if ((7 < location && location < 16 && dest == location + 16 && !board[location + 8] && !board[location + 16]) || // Special first double move
                (dest == location + 8 && !board[location + 8])) 
                return true;    // True if it can move forward to an empty square

            if ((location % 8 != 0 && (dest == location + 7 && board[location + 7] && !board[location + 7]->white)) || 
                (location % 8 != 7 && (dest == location + 9 && board[location + 9] && !board[location + 9]->white)))
                return true;    // True if it can capture an opponent's piece
        } else {    // For a black pawn:
            if ((47 < location && location < 56 && dest == location - 16 && !board[location - 8] && !board[location - 16]) || // Special first double move 
                (dest == location - 8 && !board[location - 8])) 
                return true;    // True if it can move forward to an empty square

            if ((location % 8 != 7 && (dest == location - 7 && board[location - 7] && board[location - 7]->white)) || 
                (location % 8 != 0 && (dest == location - 9 && board[location - 9] && board[location - 9]->white)))
                return true;    // True if it can capture an opponent's piece
        }
        return false;
    }
};
