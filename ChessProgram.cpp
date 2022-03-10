#include "ChessProgram.hpp"

ChessProgram::ChessProgram() {}

ChessProgram::~ChessProgram() {
    for (auto g : games) delete g;
    games.clear();
}

void ChessProgram::startGame() {
    string in = " ";
    //currentGame->swapPlayer(); // Uncomment to start as black
    while(in.at(0) != 'q') { // Currently q quits, maybe change to o for more options
        currentGame->printBoard();
        in = " ";

        while(in.size() < 1 || (in.at(0) != 'q' && !attemptMove(in))) {
            cout << "Input move: ";
            getline(cin, in);
            if (in.size() == 1) {
                if (in.at(0) == 'u') { // u undos your move
                    currentGame->undoMoves();
                    currentGame->printBoard();
                }
                if (in.at(0) == 'r') { // r moves a random piece for you
                    currentGame->swapPlayer();
                    currentGame->computerMove();
                    currentGame->swapPlayer();
                    break;
                }
            }
        }

        if (currentGame->canPromote()) { //Checks if there is a pawn that is going to be promoted
            cout << "Input Promotion: \n2 = knight\n3 = bishop\n4 = rook\n5 = queen\n"; //Output instructions for pawn promotion
            int userInput; 
            cin >> userInput; //get user input
	    while (userInput < 2 || userInput > 5) {
	        cout << "Invalid Input! Please input a number from 2-5\n";
	        cin >> userInput;
	        getline(cin, input);
	        input = " ";
	    }
            currentGame->promotePawn(userInput); //promote the pawn
            getline(cin, in); //Catches whitelines
            in = " ";
        }

        if (currentGame->announceMate()) in = "q";
        else if (in.at(0) != 'q') {
             currentGame->announceCheck();

             if (currentGame->opponentIsComputer) currentGame->computerMove();
             else currentGame->swapPlayer();

             if (currentGame->announceMate()) in = "q";
             else currentGame->announceCheck();
        }
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

ChessGame* ChessProgram::selectGame(int i) {
     if (games.empty() || i < 0 || i >= games.size()) {
	return nullptr;
     }
     return games.at(i);
}

void ChessProgram::start() {
	int menuOption = 0;
	while (menuOption != 3) {
		menuOption = loadMenu();
		if (menuOption == 1) {
			currentGame = new ChessGame;
			// vs player (option 1)
			if (PlayerComputer() == 1)
			{
				currentGame->opponentIsComputer = false;  //add this
				cout << "You are going to play another person.\n" << endl;
			}
			// vs computer (option 2)
			else {
				cout << "You are going to play vs the computer.\n" << endl;
			}
			
			// call chooseColor() and get color from user
			if (chooseColor() == 1) {
                               	cout << "You are white." << endl;
                                currentGame->setPlayerWhite();
			} else {
                                cout << "You are black." << endl;
                                currentGame->setPlayerBlack();
                        }

			getline(cin,input);
			games.push_back(currentGame);
			startGame(); //  add this
		}
		else if (menuOption == 2) {
			//cout << "load game" << endl;
			if (games.size() == 0) {
				cout << "Error: No games started!" << endl;
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
				startGame();
			}
		}

	}
	cout << "Good bye!" << endl;
}

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
	return;
}

void ChessProgram::gameMenu()
{
	cout << "********************************************************************\n";
	cout << "** Please select from the following choices:                      **\n";
	cout << "** u - undo a move (in the game)                                  **\n";
	cout << "** r - make a random move (in the game)                           **\n";
	cout << "** s - save and return to main menu                               **\n";
	cout << "** b - return back to the game                                    **\n";
	cout << "********************************************************************\n";
	return;
}

int ChessProgram::loadMenu() {
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

int ChessProgram::PlayerComputer() {
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
