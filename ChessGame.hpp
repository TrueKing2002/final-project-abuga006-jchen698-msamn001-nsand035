#ifndef CHESSGAME
#define CHESSGAME

#include "board/ChessBoard.cpp"

class ChessGame {
    private:
	ChessBoard* theBoard;
        bool playerIsWhite = true;
    public:
	ChessGame() {theBoard = new ChessBoard;}
        ~ChessGame() {delete theBoard;}
        void setPlayerWhite() {playerIsWhite = true;}
        void setPlayerBlack() {playerIsWhite = false;}
        void move(int, int);
        void printBoard();
	void computerMove();
};

#endif
