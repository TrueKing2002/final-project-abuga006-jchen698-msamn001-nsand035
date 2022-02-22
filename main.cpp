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

    cout << "\nOPPONENT MOVE d7 d5 (52, 36)\n";
    game.move(52, 36);
    game.printBoard();

    cout << "\nMOVE b1 c3 (2, 19)\n";
    game.move(2, 19);
    game.printBoard();

    cout << "\nPRINT BOARD BLACK: \n";
    game.setPlayerBlack();
    game.printBoard();

    return 1;
}
