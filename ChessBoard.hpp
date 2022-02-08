#ifndef CHESSBOARD
#define CHESSBOARD

#include "Pawn.cpp"
#include "Knight.cpp"
#include "Bishop.cpp"
#include "Rook.cpp"
#include "Queen.cpp"
#include "King.cpp"

class ChessBoard {
    private: 
        ChessPiece **board;
        bool playerIsWhite = true;
    public: 
        ChessBoard(); 
        ~ChessBoard();
        void newBoard(); 
        void printBoard();
        ChessPiece** sendBoard() {return board;}
        void setPlayerWhite() {playerIsWhite = true;}
        void setPlayerBlack() {playerIsWhite = false;}
        bool isPlayerWhite() {return playerIsWhite;}
        ChessPiece* getPiece(int i) {return board[trans(i)];}
        void movePiece(int, int);
};

#endif
