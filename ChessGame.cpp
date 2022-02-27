#include "ChessGame.hpp"

void ChessGame::move(int l, int d) {
	theBoard->movePiece(l, d);
}

void ChessGame::printBoard() {
	if (playerIsWhite) theBoard->printBoardWhite();
        else theBoard->printBoardBlack();
}

void ChessGame::computerMove() {
    srand(time(0));
    int randomLoc = rand() % 64 + 1; 
    ChessPiece* randomPiece = theBoard->getPiece(randomLoc);

    while (!randomPiece || (playerIsWhite && randomPiece->white == true) || (!playerIsWhite && randomPiece->white == false)) { 
    	randomLoc = rand() % 64 + 1;
	randomPiece = theBoard->getPiece(randomLoc);
    }                
    
    int randomDest = rand() % 64 + 1;
    
    while (!randomPiece->canMove(theBoard->sendBoard(), randomDest)) {
	randomDest = rand() % 64 + 1;
    }
    move(randomLoc, randomDest); 
}    
