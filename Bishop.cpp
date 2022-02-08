#include "ChessPiece.hpp"

class Bishop : public ChessPiece {
    string getPiece() {
        if (white) return "♝";
        else return "♗";
    }
    
    bool canMove(ChessPiece** board, int dest) {return true;}
};
