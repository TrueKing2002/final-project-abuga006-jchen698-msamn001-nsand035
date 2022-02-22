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
    public: 
        ChessBoard(); 
        ~ChessBoard();
        void newBoard(); 
        void printBoard();
        ChessPiece** sendBoard() {return board;}
        ChessPiece* getPiece(int i) {return board[trans(i)];}
        void movePiece(int, int);
	bool whiteInCheck();
	bool blackInCheck();
	void printBoardWhite();
	void printBoardBlack();
};

#endif
