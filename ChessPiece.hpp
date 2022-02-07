#ifndef CHESSPIECE
#define CHESSPIECE

#include <iostream>
using namespace std;

struct coordinate {
    public: char let; int num;
};

class ChessPiece {
    public: 
        bool white; 
        virtual string getPiece() = 0; 
        virtual bool canMove(coordinate) = 0;
};

#endif

// ♜♞♝♛♚♟♖♘♗♕♔♙
