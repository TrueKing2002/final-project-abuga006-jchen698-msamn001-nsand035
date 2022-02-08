#ifndef CHESSPIECE
#define CHESSPIECE

#include <iostream>
using namespace std;

int trans(int in) {return  in / 8 * 8 + 8 - in % 8;} // translates input to actual index

class ChessPiece {
    public: 
        bool white; 
        int location;
        virtual string getPiece() = 0; 
        virtual bool canMove(ChessPiece*[], int) = 0;
};

#endif

// ♜♞♝♛♚♟♖♘♗♕♔♙
