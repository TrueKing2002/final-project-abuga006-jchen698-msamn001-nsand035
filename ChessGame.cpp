#include "ChessGame.hpp"

bool ChessGame::move(int l, int d) {	// Assume l and d are valid board indices
    if (theBoard->getPiece(l) && theBoard->getPiece(l)->canMove(theBoard->sendBoard(), d)) { 
	if (theBoard->getPiece(l)->white != playerIsWhite) return false; // Player can only move piece of their color
 
        moveLog.push(l);
        moveLog.push(d);
        if (theBoard->getPiece(d)) moveLog.push(theBoard->getPiece(d)->id);
        else moveLog.push(0);

        theBoard->movePiece(l, d);
        return true;
    }
    //cout << "Invalid Move!" << endl;
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

void ChessGame::swapPlayer() {
    if (playerIsWhite) setPlayerBlack();
    else setPlayerWhite();
}

void ChessGame::computerMove() {
    srand(time(0) + randomSeed++);
    int randomLoc = rand() % 64 + 1; 
    int randomDest = rand() % 64 + 1;
    ChessPiece* randomPiece = theBoard->getPiece(randomLoc);

    while (!randomPiece || playerIsWhite == randomPiece->white || !randomPiece->canMove(theBoard->sendBoard(), randomDest)) { 
    	randomLoc = rand() % 64 + 1;
	randomDest = rand() % 64 + 1;
	randomPiece = theBoard->getPiece(randomLoc);
    }                
    swapPlayer();
    move(randomLoc, randomDest);
    swapPlayer(); 
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

void ChessGame::undoMove() { // Undos two moves so player can move again
    if (!moveLog.empty()) {
        swapPlayer();
        undo();
        swapPlayer();
        undo();
	cout << "UNDID MOVES" << endl;
    }
}

void ChessGame::undo() {
    ChessPiece* tempPiece = retrievePiece(moveLog.top());
    moveLog.pop();
    int tempLoc = moveLog.top();
    moveLog.pop();
    int tempDest = moveLog.top();
    moveLog.pop();
    theBoard->movePiece(tempLoc, tempDest); // Moves last piece back to old location

    tempLoc = trans(tempLoc);
    theBoard->sendBoard()[tempLoc] = tempPiece; // Replaces a captured piece if there was one
    if (tempPiece) {
        tempPiece->location = tempLoc;
        tempPiece->white = !playerIsWhite;
    }
    //if (playerIsWhite) cout << "UNDID WHITE MOVE" << endl;
    //else cout << "UNDID BLACK MOVE" << endl;
}

bool ChessGame::blackMate() {
    int kingLocation = -1;
    for (int i = 1; i < 65; i++) {
        if (theBoard->getPiece(i) != nullptr && theBoard->getPiece(i)->white == false && theBoard->getPiece(i)->id == 6) {
            kingLocation = i;
	}
    }

    if (kingLocation == -1) {cout << "\nERROR: NO BLACK KING FOUND\n";}

    if (theBoard->blackInCheck()) {
	for (int i = kingLocation - 9; i < kingLocation + 9; i++) {
	    move(kingLocation, i);
	    if (theBoard->blackInCheck()) {
	        undo();
	    }
	    else {
	        return false;
	    }
	}
    }
    return true;
}

ChessPiece* ChessGame::retrievePiece(int id) {
    if (id == 0) return nullptr;
    if (id == 1) return new Pawn;
    if (id == 2) return new Knight;
    if (id == 3) return new Bishop;
    if (id == 4) return new Rook;
    if (id == 5) return new Queen;
    if (id == 6) return new King;
    cout << "ERROR: NO PIECE FOUND" << endl;
}
