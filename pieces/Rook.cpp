#include "ChessPiece.hpp"

class Rook : public ChessPiece {
public:
    Rook() {id = 4;}

    string getPiece() {
        if (white) return "♜";
        else return "♖";
    }
    
    bool canMove(ChessPiece** board, int dest) {return false;}
};
