#include "ChessPiece.hpp"

class Bishop : public ChessPiece {
public:
    Bishop() {id = 3;}

    string getPiece() {
        if (white) return "♝";
        else return "♗";
    }
    
    bool canMove(ChessPiece** board, int dest) {return false;}		    
};
