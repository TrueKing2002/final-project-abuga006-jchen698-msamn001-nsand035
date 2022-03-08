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

    return 1;
}
