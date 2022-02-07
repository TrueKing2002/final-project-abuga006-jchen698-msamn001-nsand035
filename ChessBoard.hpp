#ifndef CHESSBOARD
#define CHESSBOARD

#include "ChessSquare.hpp"

class ChessBoard {
    private: 
        ChessSquare *board;
    public: 
        ChessBoard(); 
        ~ChessBoard();
        void newBoard(); 
        void printBoard();
};

#endif
