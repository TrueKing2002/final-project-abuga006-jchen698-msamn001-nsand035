#include "ChessProgram.hpp"

ChessProgram::ChessProgram() {
    currentGame = new ChessGame;
    games.push_back(currentGame);
}

ChessProgram::~ChessProgram() {
    for (auto g : games) delete g;
    games.clear();
}

void ChessProgram::start() {
    string input = " ";

    while(input.at(0) != 'q') { // Currently q quits, maybe change to o for more options
        currentGame->printBoard();
        input = " ";

        while(input.size() < 1 || (input.at(0) != 'q' && !attemptMove(input))) {
            cout << "Input move: ";
            getline(cin, input);
	    if (input.size() == 1) {
                if (input.at(0) == 'u') { // u undos your move
                    currentGame->undoMove();
                    currentGame->printBoard();
                }
                if (input.at(0) == 'r') { // r moves a random piece for you
                    currentGame->swapPlayer();
                    currentGame->computerMove();
                    currentGame->swapPlayer();
                    break;
                }
            }
        }
        if (input.at(0) != 'q') currentGame->computerMove();
    }
}
