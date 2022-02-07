#include "ChessPiece.hpp"

class Bishop : public ChessPiece {
    string getPiece() {
        if(white) return "♝";
        else return "♗";
    }
    
    bool canMove(coordinate coord) {return true;}
};
