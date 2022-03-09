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
    public:
        ChessProgram();
        ~ChessProgram();
        void start();
};

#endif
