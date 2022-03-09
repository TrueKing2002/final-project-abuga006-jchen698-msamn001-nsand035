#include "ChessProgram.cpp"

int main() {
    ChessProgram program;
    program.start();
    
/*
    ChessGame game;
    for (int i = 1; i < 20; i++) { // You can change the loop to run as many times as you want
        cout << "Computer Move " << i << " (White)" << endl;
	game.setPlayerBlack();
        game.computerMove();
	game.setPlayerWhite();
        game.printBoard();

        cout << "Computer Move " << ++i << " (Black)" << endl;
        game.computerMove();
        game.printBoard();
    }
*/

    ChessGame game;
	int menuOption = 0;
	while (menuOption != 3) {
		menuOption = loadMenu();
		if (menuOption == 1) {
 		    // vs player (option 1)
 		    if (int PlayerComputer() == 1) {
		        cout << "You are going to play another person.\n" << "Do you want to be white or black?\n";
		        // call chooseColor() and get color from user
		        // they picked white
		        if (chooseColor() == 1) {
		            cout << "you are white.";
			    game.printBoard();
	                }
                        // they picked black
                        else {
			    cout << "you are black.";
			    game.setPlayerBlack();
			    game.printBoard();
			}
		    }

                    // vs computer (option 2)
                    else {
                        cout << "You are going to play vs the computer.\n" << "Do you want to be white or black?\n";
 			// call chooseColor() and get color from user
 			// they picked white
 			if (chooseColor() == 1) {
                  	    cout << "you are white.";
			    game.printBoard();
			}
			
			// they picked black
			else {
			    cout << "you are black.";
			    game.setPlayerBlack();
			    game.printBoard();
			}
                    }
		}
  		else if (menuOption == 2) {
		    cout << "load game";
  		}
	}

    cout << "quit";
    return 1;
}
