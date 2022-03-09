#ifndef CHESSPROGRAM
#define CHESSPROGRAM

#include "ChessGame.cpp"
#include <vector>

class ChessProgram {
    private:
        vector<ChessGame*> games;
        ChessGame* currentGame;
        bool attemptMove(string);
    public:
        ChessProgram();
        ~ChessProgram();
        void start();
};

// functions
void printMenu();
int loadMenu();
int chooseColor();
int PlayerComputer();

#endif
