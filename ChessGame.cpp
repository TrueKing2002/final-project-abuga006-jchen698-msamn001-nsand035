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
    int randnum1 = rand() % 64; 
    ChessPiece* randomPiece = theBoard->getPiece(randnum1);

    while ((playerIsWhite && randomPiece->white == true) || (!playerIsWhite && randomPiece->white == false)) { 
    	randnum1 = rand() % 64;
    }                
    
    int randomDest = rand() % 64;
    
    while (!randomPiece->canMove(theBoard->sendBoard(), randomDest)) {
	randomDest = rand() % 64;
    }
    move(randnum1, randomDest); 
}    
