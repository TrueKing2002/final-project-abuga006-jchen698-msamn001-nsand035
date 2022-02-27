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

void ChessGame::computerMove() {
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
