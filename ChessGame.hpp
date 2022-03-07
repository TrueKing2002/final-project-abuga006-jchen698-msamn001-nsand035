#ifndef CHESSGAME_HPP
#define CHESSGAME_HPP

#include "ChessBoard.hpp"

class ChessGame {
    private:
    public:
        ChessGame();
        ~ChessGame();
        void newGame();
};

// functions
void printMenu();
int loadMenu();
int chooseColor();
int PlayerComputer();


#endif
