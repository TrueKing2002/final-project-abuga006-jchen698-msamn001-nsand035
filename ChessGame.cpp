#include "ChessGame.hpp"

bool ChessGame::move(int l, int d) {	// Assume l and d are valid board indices
    if (theBoard->getPiece(l) && theBoard->getPiece(l)->canMove(theBoard->sendBoard(), d)) { 
        moveLog.push(l);
        moveLog.push(d);
        if (theBoard->getPiece(d)) moveLog.push(theBoard->getPiece(d)->id);
        else moveLog.push(0);

        theBoard->movePiece(l, d);
        return true;
    }
    cout << "Invalid Move!" << endl;
    return false;
}

int ChessGame::inCheck() {
    if (playerIsWhite && theBoard->whiteInCheck() || !playerIsWhite && theBoard->blackInCheck()) // if player is in check
        return 2;
    else if (playerIsWhite && theBoard->blackInCheck() || !playerIsWhite && theBoard->whiteInCheck()) // if opponent is in check
        return 1;
    return 0;
}

void ChessGame::printBoard() {
	if (playerIsWhite) theBoard->printBoardWhite();
        else theBoard->printBoardBlack();
}

void ChessGame::computerMove() {
    srand(time(0) + randomSeed++);
    int randomLoc = rand() % 64 + 1; 
    int randomDest = rand() % 64 + 1;
    ChessPiece* randomPiece = theBoard->getPiece(randomLoc);

    while (!randomPiece || (playerIsWhite && randomPiece->white == true) || (!playerIsWhite && randomPiece->white == false) || !randomPiece->canMove(theBoard->sendBoard(), randomDest)) { 
    	randomLoc = rand() % 64 + 1;
	randomDest = rand() % 64 + 1;
	randomPiece = theBoard->getPiece(randomLoc);
    }                
   
    move(randomLoc, randomDest); 
    cout << "COMPUTER MOVE: ";
    announceMove(randomLoc, randomDest);
}    

void ChessGame::announceMove(int l, int d) {
    announce(l);
    if (moveLog.top() != 0) cout << "x "; // Only ouputs an 'x' if a piece was captured in the last move
    announce(d);
    cout << endl;
}

void ChessGame::announce(int c) {
    if (c % 8 == 1) cout << 'a';
    else if (c % 8 == 2) cout << 'b';
    else if (c % 8 == 3) cout << 'c';
    else if (c % 8 == 4) cout << 'd';
    else if (c % 8 == 5) cout << 'e';
    else if (c % 8 == 6) cout << 'f';
    else if (c % 8 == 7) cout << 'g';
    else cout << 'h';

    if (c < 9) cout << '1';
    else if (c < 17) cout << '2';
    else if (c < 25) cout << '3';
    else if (c < 33) cout << '4';
    else if (c < 41) cout << '5';
    else if (c < 49) cout << '6';
    else if (c < 57) cout << '7';
    else cout << '8';
    cout << ' ';
}

bool ChessGame::attemptMove(string coords) {
    if (coords.at(0) >= 'a' && coords.at(0) <= 'h' && coords.at(3) >= 'a' && coords.at(3) <= 'h' && coords.at(1) >= '1' && coords.at(1) <= '8' && coords.at(4) >= '1' && coords.at(4) <= '8') {
        int icol = coords.at(0) - 96;
        int irow = coords.at(1) - '0';
        int fcol = coords.at(3) - 96;
        int frow = coords.at(4) - '0';
        int location = icol + (8*(irow - 1));
        int dest = fcol + (8*(frow - 1));
        return move(location, dest);
    }
    return false;
}
