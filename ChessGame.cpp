#include "ChessGame.hpp"

ChessGame::ChessGame() {}

ChessGame::~ChessGame() {}

void ChessGame::newGame() {}

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

// ask for white or black
/*int chooseColor() {
	int color = 0;
	cout << "Would you like to play as white or black?\n"
		+ "Choose 1 for white, or 2 for black\n";
	cin >> color;

	if (color != 1 || color != 2) {
		"Invalid option, please enter 1 or 2";
		int chooseColor();
	}

	return color;
}*/
