#include "ChessPiece.hpp"

class Rook : public ChessPiece {
    string getPiece() {
        if(white) return "♜";
        else return "♖";
    }
    
    bool canMove(coordinate coord) {return true;}
};
