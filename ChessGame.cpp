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
    srand(time(0));
    int randomLoc = rand() % 64 + 1; 
    int randomDest = rand() % 64 + 1;
    ChessPiece* randomPiece = theBoard->getPiece(randomLoc);

    while (!randomPiece || (playerIsWhite && randomPiece->white == true) || (!playerIsWhite && randomPiece->white == false) || (!randomPiece->canMove(theBoard->sendBoard(), randomDest)) { 
    	randomLoc = rand() % 64 + 1;
	randomDest = rand() % 64 + 1;
	randomPiece = theBoard->getPiece(randomLoc);
    }                
   
    move(randomLoc, randomDest);
}    
