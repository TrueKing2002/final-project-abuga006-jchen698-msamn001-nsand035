#ifndef CHESSPROGRAM
#define CHESSPROGRAM

#include "ChessGame.cpp"
#include <vector>
#include <string>

class ChessProgram {
    private:
        vector<ChessGame*> games;
        ChessGame* currentGame;
        bool attemptMove(string);
    public:
        ChessProgram();
        ~ChessProgram();
        void start();
	bool attemptMove(string);
};

#endif
