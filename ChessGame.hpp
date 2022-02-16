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

void printMenu();
int loadMenu();
//int chooseColor();


#endif
