#include "ChessGame.hpp"

void ChessGame::move(int l, int d) {
	theBoard->movePiece(l, d);
}

void ChessGame::printBoard() {
	if (playerIsWhite) theBoard->printBoardWhite();
        else theBoard->printBoardBlack();
}
