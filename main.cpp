#include "ChessGame.cpp"

int main() {
    ChessGame game;  // Player is white by default
    cout << "PRINT BOARD WHITE:\n";
    game.printBoard(); 

    game.setPlayerBlack();  // Changes player to black
    cout << "\nPRINT BOARD BLACK:\n";
    game.printBoard();
    
    game.setPlayerWhite();  // Changes player back to white
    cout << "\nMOVE b1 a3 (2, 17)\n";
    game.move(2, 17);
    game.printBoard();

    cout << "\nOPPONENT MOVE a3 h5 (17, 40)\n";
    game.move(17, 40);
    game.printBoard();

    cout << "\nMOVE a3 g4 (17, 31)\n";
    game.move(17, 31);
    game.printBoard();

    cout << "\nMOVE g1 f3 (7, 22)\n";
    game.move(7, 22);
    game.printBoard();

    cout << "\nMOVE f3 h4 (22, 32)\n";
    game.move(22, 32);
    game.printBoard();

/*
    cout << "\nMOVE g1 h3 (7, 24)\n";
    game.move(7, 24);
    game.printBoard();

    cout << "\nMOVE h3 a5 (24, 33)\n";
    game.move(24, 33);
    game.printBoard();

    cout << "\nMOVE h3 b4 (24, 26)\n";
    game.move(24, 26);
    game.printBoard();

    cout << "\nMOVE b2 b4 (10, 26)\n";
    game.move(10, 26);
    game.printBoard();

    cout << "\nMOVE b4 b5 (26, 34)\n";
    game.move(26, 34);
    game.printBoard();

    cout << "\nMOVE a3 b5 (17, 34)\n";
    game.move(17, 34);
    game.printBoard();

    cout << "\nPRINT BOARD BLACK: \n";
    game.setPlayerBlack();
    game.printBoard(); */
/*
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
