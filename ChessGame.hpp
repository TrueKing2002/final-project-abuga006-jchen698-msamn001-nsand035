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
	int randomSeed = 0;
    public:
	ChessGame() {theBoard = new ChessBoard;}
        ~ChessGame() {delete theBoard;}
	bool currentPlayer = 1;
	bool opponentIsComputer = true;
        void setPlayerWhite() {playerIsWhite = true;}
        void setPlayerBlack() {playerIsWhite = false;}
	void swapPlayer();
        bool move(int, int);
	int inCheck();
        void printBoard();
	void computerMove();
	void announceMove(int, int);
};

#endif
