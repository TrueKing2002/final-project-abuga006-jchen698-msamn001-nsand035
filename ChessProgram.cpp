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

bool ChessProgram::attemptMove(string coords) {
    if (coords.length() < 5) return false;
    if (coords.at(0) >= 'a' && coords.at(0) <= 'h' && coords.at(3) >= 'a' && coords.at(3) <= 'h' && coords.at(1) >= '1' && coords.at(1) <= '8' && coords.at(4) >= '1' && coords.at(4) <= '8') {
         int icol = coords.at(0) - 96;
         int irow = coords.at(1) - '0';
         int fcol = coords.at(3) - 96;
         int frow = coords.at(4) - '0';
         int location = icol + (8*(irow - 1));
         int dest = fcol + (8*(frow - 1));
         if (currentGame->move(location, dest)) {
	     cout << "YOUR MOVE: ";
	     currentGame->announceMove(location, dest);
	     return true;
	 }
     }
     return false;
}

// Nick's stuff

//prints menu
void printMenu()
{
	cout << "\n********************************************************************\n";
	cout << "**                                                                **\n";
	cout << "**             Welcome to the Chess menu                          **\n";
	cout << "**                                                                **\n";
	cout << "********************************************************************\n";
	cout << "** Please select from the following choices:                      **\n";
	cout << "** 1) Create a new game                                           **\n";
	cout << "** 2) Load a saved game                                           **\n";
	cout << "** 3) Exit                                                        **\n";
	cout << "********************************************************************\n";
	return;
}

// function to get user choice 1, 2, 3
int loadMenu() {
	string choice = " ";
	int choiceNum = 0;
	while (choice != "3") {
		choice = " ";

		while (choice != "1" && choice != "2" && choice != "3") {
			printMenu();
			cin >> choice;
		}
		if (choice == "1") {
			choiceNum = 1;
		}
		else if (choice == "2") {
			choiceNum = 2;
		}
		else
			choiceNum = 3;
		return choiceNum;

	}
	cout << "exit";
}

// aks user for white or black
int chooseColor() {
	string color = " ";
	int colorInt = 0;
	cout << "Would you like to play as white or black?\n";
	cout << "Choose 1 for white, or 2 for black\n";
	while (color != "1" && color != "2") {
		cin >> color;
		cout << "Please enter 1 for white or 2 for black: ";
	}
	if (color == "1") {
		colorInt = 1;
	}
	else {
		colorInt = 2;
	}
	return colorInt;
}

// ask for vs player or computer
int PlayerComputer() {
	string vs = " ";
	int vsInt = 0;
	cout << "Would you like to play vs another player or computer?\n";
	cout << "Choose 1 to vs another player, or 2 to vs the computer\n";
	while (vs != "1" && vs != "2") {
		cin >> vs;
		cout << "Please enter 1 to vs another player or 2 to vs the computer: ";
	}
	if (vs == "1") {
		vsInt = 1;
	}
	else {
		vsInt = 2;
	}
	return colorInt;
}
