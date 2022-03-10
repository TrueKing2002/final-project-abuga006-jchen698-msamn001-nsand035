#include "ChessGame.hpp"

bool ChessGame::move(int l, int d) {	// Assume l and d are valid board indices
    if (theBoard->getPiece(l) && theBoard->getPiece(l)->canMove(theBoard->sendBoard(), d)) {
        moveLog.push(l);
        moveLog.push(d);
        
	bool capturedPiece = false;
        int color, id;
        if (theBoard->getPiece(d)) {
            color = theBoard->getPiece(d)->white;
            id = theBoard->getPiece(d)->id;
            capturedPiece = true;
        }

        theBoard->movePiece(l, d);

        if (canPromote()) moveLog.push(1);
        else moveLog.push(-1);

        if (capturedPiece) {
            moveLog.push(color);
            moveLog.push(id);
        } else {
            moveLog.push(-1);
            moveLog.push(0);
        }

        return true;
    }
    //cout << "Invalid Move!" << endl;
    return false;
}

void ChessGame::printBoard() {
    if (playerIsWhite) theBoard->printBoardWhite();
    else theBoard->printBoardBlack();
}

void ChessGame::swapPlayer() {
    if (playerIsWhite) setPlayerBlack();
    else setPlayerWhite();
}

bool ChessGame::sameColor(int l) {
    if (theBoard->getPiece(l) && playerIsWhite == theBoard->getPiece(l)->white)
	return true;
    return false;
}

void ChessGame::computerMove() {
    swapPlayer();
    if (!playerInMate()) {
   	srand(time(0) + randomSeed++);
   	int randomLoc = rand() % 64 + 1; 
    	int randomDest = rand() % 64 + 1;
    	ChessPiece* randomPiece = theBoard->getPiece(randomLoc);

	bool needMove = true;
	while (needMove) {
    	    while (!randomPiece || playerIsWhite != randomPiece->white || !randomPiece->canMove(theBoard->sendBoard(), randomDest)) { 
    	    	randomLoc = rand() % 64 + 1;
	    	randomDest = rand() % 64 + 1;
	    	randomPiece = theBoard->getPiece(randomLoc);
    	    }                
    	    move(randomLoc, randomDest);
	    if (!playerInCheck()) needMove = false;
	    else {
	    	undo();
	    	randomPiece = nullptr;
    	    }
	    if (canPromote()) {
                if (rand() % 2 == 0) promotePawn(5); // Promotes to queen
                else promotePawn(2); // Promotes to knight
            }
	}
    	cout << "COMPUTER MOVE: ";
    	announceMove(randomLoc, randomDest);
    }
    swapPlayer();
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

void ChessGame::undoMoves() { // Undos two moves so player can move again
    if (!moveLog.empty()) {
        undo();
        if (!moveLog.empty()) {
            undo();
	    cout << "UNDID MOVES" << endl;
	}
	else cout << "UNDID MOVE" << endl;
    }
}

void ChessGame::undo() {
    ChessPiece* tempPiece = retrievePiece(moveLog.top());
    moveLog.pop();
    int color = moveLog.top();
    moveLog.pop();

    bool promoted = false;
    if (moveLog.top() == 1) {
        promoted = true;
    }
    moveLog.pop();

    int tempLoc = moveLog.top();
    moveLog.pop();

    if (promoted) {
        int color = theBoard->getPiece(tempLoc)->white;
        delete theBoard->getPiece(tempLoc);
        theBoard->sendBoard()[trans(tempLoc)] = new Pawn; // Replaces a promoted piece back to pawn
        theBoard->getPiece(tempLoc)->location = trans(tempLoc);
        theBoard->getPiece(tempLoc)->white = color;
    }

    int tempDest = moveLog.top();
    moveLog.pop();
    theBoard->movePiece(tempLoc, tempDest); // Moves last piece moved back to old location

    tempLoc = trans(tempLoc);
    theBoard->sendBoard()[tempLoc] = tempPiece; // Replaces a captured piece if there was one
    if (tempPiece) {
        tempPiece->location = tempLoc;
        tempPiece->white = color;
    }
    //if (playerIsWhite) cout << "UNDID WHITE MOVE" << endl;
    //else cout << "UNDID BLACK MOVE" << endl;
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

bool ChessGame::playerInCheck() {
    if (playerIsWhite) return theBoard->whiteInCheck();
    return theBoard->blackInCheck();
}

bool ChessGame::playerInMate() {
    if (playerIsWhite) return whiteMate();
    return blackMate();
}

bool ChessGame::whiteMate() {
    for (int l = 1; l < 65; l++)
        if (theBoard->getPiece(l) && theBoard->getPiece(l)->white)
            for (int d = 1; d < 65; d++) {
                if (move(l, d)) {
                    if (!theBoard->whiteInCheck()) {
                        undo();
                        return false;
                    }
                    undo();
                }
            }
    return true;            
}

bool ChessGame::blackMate() {
    for (int l = 1; l < 65; l++)
        if (theBoard->getPiece(l) && !theBoard->getPiece(l)->white)
            for (int d = 1; d < 65; d++) {
                if (move(l, d)) {
                    if (!theBoard->blackInCheck()) {
                        undo();
                        return false;
                    }
                    undo();
                }
            }
    return true;            
}

bool ChessGame::canPromote() {
    for (int i = 1; i < 65; i++) { //Traverse whole board 
	int row = i / 8; //Check which row the index is on
	if (i % 8 != 0) { //Make sure if it's not a special edge case to add 1 to the row to the correct row
	    row += 1;
	}
	if (theBoard->getPiece(i) && theBoard->getPiece(i)->id == 1 && (row == 1 || row == 8)) { //If the index holds a pawn on either end of the board, return true
	    return true;
	}
    }
    return false;
}

void ChessGame::promotePawn(int pieceType) {
    ChessPiece* tempPiece = retrievePiece(pieceType); //Set a temporary piece to be the promoted piece
    for (int l = 1; l < 65; l++) { //Traverse whole board
	int row = l / 8; //Check which row the index is on
	if (l % 8 != 0) { //Make sure to increment the row by 1 if it iis not on colunn h
	    row += 1;
	}
	if (theBoard->getPiece(l) && theBoard->getPiece(l)->id == 1 && (row == 1 || row == 8)) { //If the index holds a pawn that can promote
	    bool color = true; //Set the color to white
	    if (!theBoard->getPiece(l)->white) { //Check if the piece is white, if it isn't, then set color to false (black)
		color = false;
	    } 
  	    delete theBoard->getPiece(l);
	    l = trans(l);
	    theBoard->sendBoard()[l] = tempPiece; //Replace the piece at that index to the promoted piece
	    tempPiece->location = l; //Set the promoted piece's correct location
	    tempPiece->white = color; //set the promoted piece's correct color
	}
    }
}

void ChessGame::announceCheck() {
    if (theBoard->whiteInCheck()) cout << "WHITE CHECK!" << endl;
    if (theBoard->blackInCheck()) cout << "BLACK CHECK!" << endl;
}

bool ChessGame::announceMate() {
    if (whiteMate()) {
        if (theBoard->whiteInCheck()) cout << "WHITE CHECKMATE" << endl;
        else cout << "WHITE STALEMATE" << endl;
        printBoard();
	cout << "Good game!" << endl;
        return true;
    }
    if (blackMate()) {
        if (theBoard->blackInCheck()) cout << "BLACK CHECKMATE" << endl;
        else cout << "BLACK STALEMATE" << endl;
        printBoard();
	cout << "Good game!" << endl;
        return true;
    }
    return false;
}
