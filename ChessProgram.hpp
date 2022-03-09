#ifndef CHESSPROGRAM
#define CHESSPROGRAM

#include "ChessGame.cpp"
#include <vector>

class ChessProgram {
    private:
        vector<ChessGame*> games;
        ChessGame* currentGame;
        bool attemptMove(string);
	ChessGame* selectGame(int);
	string input = " ";
	void startGame();
	void printMenu();
	void gameMenu();
	int chooseColor();
	int PlayerComputer();
	int loadMenu();	

    public:
        ChessProgram();
        ~ChessProgram();
        void start();
};

#endif
