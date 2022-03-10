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
	ChessPiece* retrievePiece(int);
	bool whiteMate();
	bool blackMate();
    public:
	ChessGame() {theBoard = new ChessBoard;}
        ~ChessGame() {delete theBoard;}
	bool currentPlayer = 1;
	bool opponentIsComputer = true;
	bool sameColor(int);
        void setPlayerWhite() {playerIsWhite = true;}
        void setPlayerBlack() {playerIsWhite = false;}
	void swapPlayer();
        bool move(int, int);
        void printBoard();
	void computerMove();
	void announceMove(int, int);
	void undoMoves();
	void undo();
	bool playerInCheck();
	bool playerInMate();
	bool canPromote();
	void promotePawn(int);
	void announceCheck();
	bool announceMate();
};

#endif
