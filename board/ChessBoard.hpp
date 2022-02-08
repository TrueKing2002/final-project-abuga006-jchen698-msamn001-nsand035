#ifndef CHESSBOARD
#define CHESSBOARD

#include "../pieces/Pawn.cpp"
#include "../pieces/Knight.cpp"
#include "../pieces/Bishop.cpp"
#include "../pieces/Rook.cpp"
#include "../pieces/Queen.cpp"
#include "../pieces/King.cpp"

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
