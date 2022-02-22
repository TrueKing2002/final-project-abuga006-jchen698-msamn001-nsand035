#include "ChessPiece.hpp"

class Queen : public ChessPiece {
public:
    Queen() {id = 5;}

    string getPiece() {
        if (white) return "♛";
        else return "♕";
    }
    
    bool canMove(ChessPiece** board, int dest) {return true;}
};
