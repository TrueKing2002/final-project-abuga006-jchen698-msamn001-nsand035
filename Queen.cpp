#include "ChessPiece.hpp"

class Queen : public ChessPiece {
    string getPiece() {
        if(white) return "♛";
        else return "♕";
    }
    
    bool canMove(coordinate coord) {return true;}
};
