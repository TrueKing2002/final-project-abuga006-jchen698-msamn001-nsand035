#include "ChessPiece.hpp"

class King : public ChessPiece {
public:
    King() {id = 6;}

    string getPiece() {
        if (white) return "♚";
        else return "♔";
    }
    
    bool canMove(ChessPiece** board, int dest) {return true;}
};
