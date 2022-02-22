#include "board/ChessBoard.cpp"
#include "ChessGame.hpp"
//#include "ChessGame.hpp"
#include <iostream>
using namespace std;

int main() {

	int menuOption = 0;
	while (menuOption != 3) {
		menuOption = loadMenu();
		if (menuOption == 1) {
			// call chooseColor() and get color from user
			// they picked white
			if (chooseColor() == 1) {
				cout << "you are white.";
			}
			// they picked black
			else {
				cout << "you are black.";
			}
			// player or computer?
			cout << "start new Game";
		}
		else if (menuOption == 2) {
			cout << "load game";
		}

	}
	cout << "quit";
	return 0;
	
	



    ChessBoard game;  // Player is white by default
    cout << "PRINT BOARD WHITE:\n";
    game.printBoard(); 

    game.setPlayerBlack();  // Changes player to black
    cout << "\nPRINT BOARD BLACK:\n";
    game.printBoard();
    
    game.setPlayerWhite();  // Changes player back to white
    cout << "\nMOVE e2 e4 (13, 29)\n";
    game.movePiece(13, 29);
    game.printBoard();

    cout << "\nOPPONENT MOVE d7 d5 (52, 36)\n";
    game.movePiece(52, 36);
    game.printBoard();

    cout << "\nMOVE b1 c3 (2, 19)\n";
    game.movePiece(2, 19);
    game.printBoard();

    cout << "\nPRINT BOARD BLACK: \n";
    game.setPlayerBlack();
    game.printBoard();

    return 1;
}
