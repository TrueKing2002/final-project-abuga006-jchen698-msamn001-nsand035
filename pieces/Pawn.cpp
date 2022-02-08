#include "ChessPiece.hpp"

class Pawn : public ChessPiece {
    string getPiece() {
        if (white) return "♟";
        else return "♙";
    }
    
    bool canMove(ChessPiece** board, int dest) {    // NOT COMPLETE - FOR REFERENCE ONLY
        dest = trans(dest);
        if (white) {    // For a white pawn:
            if ((dest == location + 16 && board[location + 16] == nullptr) || 
                (dest == location + 8 && board[location + 8] == nullptr)) 
                return true;    // Checks if it can move forward to an empty square

            if ((dest == location + 7 && board[location + 7] != nullptr && !board[location + 7]->white) || 
                (dest == location + 9 && board[location + 9] != nullptr && !board[location + 9]->white))
                return true;    // Checks if it can capture an opponent's piece
        } else {    // For a black pawn:
            if ((dest == location - 16 && board[location - 16] == nullptr) || 
                (dest == location - 8 && board[location - 8] == nullptr)) 
                return true;    // Checks if it can move forward to an empty square

            if ((dest == location - 7 && board[location - 7] != nullptr && board[location - 7]->white) || 
                (dest == location - 9 && board[location - 9] != nullptr && board[location - 9]->white))
                return true;    // Checks if it can capture an opponent's piece
        }
        return false;
    }
};
