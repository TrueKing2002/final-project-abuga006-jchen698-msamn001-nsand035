#ifndef CHESSGAME
#define CHESSGAME

#include "board/ChessBoard.cpp"
#include <stack>

class ChessGame {
    private:
	ChessBoard* theBoard;
        bool playerIsWhite = true;
	stack<int> moveLog;
	void announce(int);
    public:
	ChessGame() {theBoard = new ChessBoard;}
        ~ChessGame() {delete theBoard;}
        void setPlayerWhite() {playerIsWhite = true;}
        void setPlayerBlack() {playerIsWhite = false;}
        bool move(int, int);
	int inCheck();
        void printBoard();
	void computerMove();
	void announceMove(int, int);
};

#endif
