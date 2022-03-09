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
    //currentGame->swapPlayer(); // Uncomment to start as black
    while(input.at(0) != 'q') { // Currently q quits, maybe change to o for more options
        currentGame->printBoard();
        input = " ";

        while(input.size() < 1 || (input.at(0) != 'q' && !attemptMove(input))) {
            cout << "Input move: ";
            getline(cin, input);
	    if (input.size() == 1) {
                if (input.at(0) == 'u') { // u undos your move
                    currentGame->undoMoves();
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
	if (currentGame->canPromote()) {
	    cout << "Input Promotion: \n2 = knight\n3 = bishop\n4 = rook\n5 = queen\n";
	    int userInput;
	    cin >> userInput;
	    currentGame->promotePawn(userInput);
	    currentGame->printBoard();
	}
	if (currentGame->announceMate()) input = "q";
        else if (input.at(0) != 'q') {
	    currentGame->announceCheck();
	    currentGame->computerMove();

	    if (currentGame->announceMate()) input = "q";
	    else currentGame->announceCheck();
	}
	if (input == "q") cout << "Good game!" << endl;
    }
}

bool ChessProgram::attemptMove(string coords) {
    if (coords.length() < 5) return false;
    if (coords.at(0) >= 'a' && coords.at(0) <= 'h' && coords.at(3) >= 'a' && coords.at(3) <= 'h' && coords.at(1) >= '1' && coords.at(1) <= '8' && coords.at(4) >= '1' && coords.at(4) <= '8') {
         int icol = coords.at(0) - 96;
         int irow = coords.at(1) - '0';
         int fcol = coords.at(3) - 96;
         int frow = coords.at(4) - '0';
         int location = icol + (8*(irow - 1));
         int dest = fcol + (8*(frow - 1));
         if (currentGame->sameColor(location) && currentGame->move(location, dest)) {
	     if (currentGame->playerInCheck()) {
		currentGame->undo();
		return false;
	     }
	     cout << "YOUR MOVE: ";
	     currentGame->announceMove(location, dest);
	     return true;
	 }
     }
     return false;
}
