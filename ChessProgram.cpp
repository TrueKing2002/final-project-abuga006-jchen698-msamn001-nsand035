#include "ChessProgram.hpp"

ChessProgram::ChessProgram() {}

ChessProgram::~ChessProgram() {
    for (auto g : games) delete g;
    games.clear();
}

void ChessProgram::startGame() {
    string input = " ";
    //currentGame->swapPlayer();  // Uncomment to start as black as default
    while(input.at(0) != 's') { // s = save and quit to main menu
        currentGame->printBoard();
        input = " ";

        while(input.size() < 1 || (input.at(0) != 's' && !attemptMove(input))) {
            cout << "Input move (or enter 'o' for more options): ";
            getline(cin, input);
            //cin >> input;
            if (input.size() == 1) {
                if (input.at(0) == 'o') {
                    if (currentGame->allowCheats) printGameMenu();
                    else printGameMenuNoCheats();

                    cin >> input;
                    if (input == "b") {
                        input = " ";
                        currentGame->printBoard();
                    } 
                    cin.ignore();
                }
                if (input.at(0) == 'u' && currentGame->allowCheats) { // u undos your move
                    cout << endl;

                    if (currentGame->opponentIsComputer) currentGame->undoMoves(2);
                    else if (currentGame->undoMoves(1)) currentGame->swapPlayer();
                    currentGame->printBoard();
                }
                if (input.at(0) == 'r' && currentGame->allowCheats) break;
            }
        }

        if (input.at(0) == 'r') { // r moves a random piece for you
            cout << endl;
            currentGame->swapPlayer();
            currentGame->computerMove();
            currentGame->swapPlayer();
        }

        if (currentGame->canPromote()) { // Checks if there is a pawn that is going to be promoted
            cout << "Input Promotion: \n2 = knight\n3 = bishop\n4 = rook\n5 = queen\n";
            cin >> input; // gets user input
            while (input < "2" || input > "5") {
                cout << "Invalid Input! Please input a number from 2-5: ";
                cin >> input;
            }            
            currentGame->promotePawn(stoi(input));  // promotes the pawn
            getline(cin, input); // Catches whitespace
            input = " ";
            cout << endl;
 	    }

        if (currentGame->announceMate() >= 0) input = "s";
        else if (input.at(0) != 's') {
            currentGame->announceCheck();

            if (currentGame->opponentIsComputer) {
                cout << endl;
                currentGame->computerMove();
                if (currentGame->announceMate() >= 0) input = "s";
                else currentGame->announceCheck();
            }
            else currentGame->swapPlayer();
        }
    }
}

bool ChessProgram::attemptMove(string coords) { // By Megan Samn and me
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
            cout << "\nYOUR MOVE: ";
            currentGame->announceMove(location, dest);
            return true;
        }
    }
    return false;
}

ChessGame* ChessProgram::selectGame(int i) {
    if (games.empty() || i < 0 || i >= games.size())
	    return nullptr;
    return games.at(i);
}

void ChessProgram::start() { // By Nick Sandburg, edited by me
	int menuOption = 0;
        while (menuOption != 3) {
		menuOption = loadMenu();
		if (menuOption == 1) { // Create a new game
			currentGame = new ChessGame;
            bool isBlack = false;
			// vs player (option 1)
			if (playerComputer() == 1) {
				currentGame->opponentIsComputer = false;  //add this
				cout << "You are going to play another person." << endl;
			}
			// vs computer (option 2)
			else {
                cout << "You are going to play vs the computer.\n" << endl;
                
                // call chooseColor() and get color from user
                if (chooseColor() == 1) {
                    cout << "You are white." << endl;
                    currentGame->setPlayerWhite();
                } else {
                    cout << "You are black." << endl;
                    currentGame->setPlayerBlack();
                    isBlack = true;
                }
            }
            
            cout << endl;
            if (!allowCheats()) currentGame->allowCheats = false;
            if (isBlack) currentGame->computerMove();

			getline(cin,input);
			games.push_back(currentGame);
			startGame(); //  add this
		}
		else if (menuOption == 2) { // Load a saved game
			//cout << "load game" << endl;
			if (games.size() == 0) {
				cout << "No games started." << endl;
			}
			else {
				currentGame = nullptr;
				while (currentGame == nullptr) {
					cout << "Please select a game from 1 to " << games.size() << ": ";
					cin >> input;
					if (input > "0" && input <= to_string(games.size()))
						currentGame = selectGame(stoi(input) - 1);
				}
				getline(cin,input);
                if (currentGame->announceMate() < 0)
				    startGame();
			}
		}

	}
	cout << "\nGood bye!\n";
}

// Everything below by Nick Sandburg
void ChessProgram::printMenu()
{
	cout << "\n********************************************************************\n";
	cout << "**                                                                **\n";
	cout << "**                  Welcome to the Chess menu                     **\n";
	cout << "**                                                                **\n";
	cout << "********************************************************************\n";
	cout << "** Please select from the following choices:                      **\n";
	cout << "** 1) Create a new game                                           **\n";
	cout << "** 2) Load a saved game                                           **\n";
	cout << "** 3) Exit                                                        **\n";
	cout << "********************************************************************\n";
    cout << ">> ";
	return;
}

void ChessProgram::printGameMenu()
{
	cout << "********************************************************************\n";
	cout << "** Please select from the following choices:                      **\n";
	cout << "** u - undo a move                                                **\n";
	cout << "** r - make a random move                                         **\n";
	cout << "** s - save and quit to main menu                                 **\n";
	cout << "** b - return back to the game                                    **\n";
	cout << "********************************************************************\n";
    cout << ">> ";
	return;
}

void ChessProgram::printGameMenuNoCheats()
{
	cout << "********************************************************************\n";
	cout << "** Please select from the following choices:                      **\n";
	cout << "** s - save and quit to main menu                                 **\n";
	cout << "** b - return back to the game                                    **\n";
	cout << "********************************************************************\n";
    cout << ">> ";
	return;
}

int ChessProgram::loadMenu() {
	string choice = " ";
	int choiceNum = 0;

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

int ChessProgram::chooseColor() {
	string color = " ";
	int colorInt = 0;
	cout << "Would you like to play as white or black?\n";
	//cout << "Choose 1 for white, or 2 for black\n";
	while (color != "1" && color != "2") {
		cout << "Please enter 1 for white or 2 for black: ";
		cin >> color;
	}
	if (color == "1") {
		colorInt = 1;
	}
	else {
		colorInt = 2;
	}
	return colorInt;
}

int ChessProgram::playerComputer() {
	string vs = " ";
	int vsInt = 0;
	cout << "Would you like to play vs another player or computer?\n";
	//cout << "Choose 1 to vs another player, or 2 to vs the computer\n";
	while (vs != "1" && vs != "2") {
		cout << "Please enter 1 to vs another player or 2 to vs the computer: ";
		cin >> vs;
	}
	if (vs == "1") {
		vsInt = 1;
	}
	else {
		vsInt = 2;
	}
	return vsInt;
}

int ChessProgram::allowCheats() {
    string choice = " ";
	int choiceNum = 0;
	cout << "Allow cheats? (undos and random moves)\n";
	while (choice != "1" && choice != "2") {
		cout << "Please enter 1 for yes or 2 for no: ";
		cin >> choice;
	}
	if (choice == "2") {
		choiceNum = 0;
	}
	else {
		choiceNum = 1;
	}
	return choiceNum;
}
