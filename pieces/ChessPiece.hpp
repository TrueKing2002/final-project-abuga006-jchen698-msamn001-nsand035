#ifndef CHESSPIECE
#define CHESSPIECE

#include <iostream>
using namespace std;

int trans(int in) {if (in % 8 == 0) return in - 8; return  in / 8 * 8 + 8 - in % 8;} // translates input to actual index

class ChessPiece {
    protected:
        bool atEdge(int i) {if(i % 8 == 0 || i % 8 == 7) return true; return false;}
    public: 
	int id = -1;
        bool white; 
        int location;
        virtual string getPiece() = 0; 
        virtual bool canMove(ChessPiece*[], int) = 0;
};

#endif

// ♜♞♝♛♚♟♖♘♗♕♔♙
