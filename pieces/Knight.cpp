#include "ChessPiece.hpp"

class Knight : public ChessPiece {
public:
    Knight() {id = 2;}

    string getPiece() {
        if (white) return "♞";
        else return "♘";
    }
    
    bool canMove(ChessPiece** board, int dest) {return true;}
};
