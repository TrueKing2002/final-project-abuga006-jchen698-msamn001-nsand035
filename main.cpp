#include "ChessGame.cpp"

int main() {
    ChessGame game;  // Player is white by default
    cout << "PRINT BOARD WHITE:\n";
    game.printBoard(); 

    game.setPlayerBlack();  // Changes player to black
    cout << "\nPRINT BOARD BLACK:\n";
    game.printBoard();
    
    game.setPlayerWhite();  // Changes player back to white
    cout << "\nMOVE e2 e4 (13, 29)\n";
    game.move(13, 29);
    game.printBoard();

    cout << "\nOPPONENT MOVE f6 a6 (6, 41)\n";
    game.move(6, 41);
    game.printBoard();

    cout << "\nMOVE a6 f3 (41, 22)\n";
    game.move(41, 22);
    game.printBoard();

    cout << "\nMOVE a6 h5 (41, 40) \n";
    game.move(41, 40);
    game.printBoard();

    cout << "\nMOVE c3 h6 (3, 48) \n";
    game.move(3, 48);
    game.printBoard();

    cout << "\nMOVE d2 d3 (12, 20)\n";
    game.move(12, 20);
    game.printBoard();

    cout << "\nMOVE c3 h6 (3, 48) \n";
    game.move(3, 48);
    game.printBoard(); 

    cout << "\nPRINT BOARD BLACK: \n";
    game.setPlayerBlack();
    game.printBoard();
/*
    for (int i = 1; i < 20; i++) {
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
