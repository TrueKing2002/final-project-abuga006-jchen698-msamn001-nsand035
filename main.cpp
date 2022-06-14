#include "ChessProgram.cpp"

int main() {
    ChessProgram program;
    program.start();
    
    string input = "0";
    while (input < "1" || input > "2") {
        cout << "Enter '1' to start program or '2' to compute endgame: ";
        cin >> input;
    }
    if (stoi(input) == 2) {
        cout << "White Checkmate/Stalemate = 1/2" << endl;
        cout << "Black Checkmate/Stalemate = 3/4" << endl;

        string expectedEndGame = "0";
        while (expectedEndGame < "1" || expectedEndGame > "4") {
            cout << "Enter 1-4: ";
            cin >> expectedEndGame;
        }

        ChessGame game;
        int endGame = -1;
        int gamesPlayed = 0;
        while (endGame != stoi(expectedEndGame)) {
            int i = 1;
            gamesPlayed++;
            while (i < 1000) {
                cout << "[Game " << gamesPlayed << "] ";
                cout << "Computer Move " << i++;
                if (game.currentPlayer)  cout << " (White)";
                else cout << " (Black)";
                cout << endl;

                if (game.playerInMate()) break;
                else {
                    game.swapPlayer();
                    game.computerMove();
                }

                if (!game.currentPlayer) {
                    game.swapPlayer();
                    game.printBoard();
                    game.swapPlayer();
                }
                else game.printBoard();
            }
            game.setPlayerWhite();
            endGame = game.announceMate();
            game.resetBoard();
        }
    }
    else {  // This starts the main Chess program
        getline(cin, input);
        ChessProgram program;
        program.start();
    }

    return 1;
}
