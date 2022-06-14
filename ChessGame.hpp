#ifndef CHESSGAME
#define CHESSGAME

#include "board/ChessBoard.cpp"
#include <stack>
#include <vector>
#include <time.h>

class ChessGame {
    private:
        ChessBoard* theBoard;
        bool playerIsWhite() {return currentPlayer;}
        stack<int> moveLog;
        int randomSeed = 0;
        void announce(int);
        ChessPiece* retrievePiece(int);
        bool canCheck();
        bool whiteMate();
        bool blackMate();
        bool onlyKings();
	
    public:
        ChessGame() {theBoard = new ChessBoard;}
        ~ChessGame() {delete theBoard;}
        bool currentPlayer = 1;
        bool opponentIsComputer = true;
        void setPlayerWhite() {currentPlayer = 1;}
        void setPlayerBlack() {currentPlayer = 0;}
        void swapPlayer();
        bool move(int, int);
        void computerMove();
        bool sameColor(int);
        void printBoard();
        void announceMove(int, int);
        void undo();
        bool undoMoves(int);
        bool playerInCheck();
        bool playerInMate();
        void announceCheck();
        int announceMate();
        bool canPromote();
        void promotePawn(int);
        void resetBoard() {delete theBoard; theBoard = new ChessBoard;}
        bool allowCheats = true; // Undos and random (computer) moves ON by default
};

#endif
