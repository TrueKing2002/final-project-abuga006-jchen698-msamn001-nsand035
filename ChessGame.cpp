#include "ChessGame.hpp"

bool ChessGame::move(int l, int d) {
    if (theBoard->getPiece(l) && theBoard->getPiece(l)->canMove(theBoard->sendBoard(), d)) { // Assume l and d are valid board indices
        if (theBoard->getPiece(d) && theBoard->getPiece(d)->id == 6) return false;

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
    //cout << "Illegal Move!" << endl;
    return false;
    //if (theBoard->whiteInCheck()) cout << "\nWHITE IN CHECK\n";
    //if (theBoard->blackInCheck()) cout << "\nBLACK IN CHECK\n";
}

bool ChessGame::undoMoves(int n) { // Undos either one, two, or no moves
    if (!moveLog.empty() && n == 1) {
        undo();
        cout << "UNDID MOVE" << endl;
        return true;
    }
    else if (!moveLog.empty() && moveLog.size() > 7) {
        undo();
        undo();
        cout << "UNDID MOVES" << endl;
        return true;
    }
    else cout << "No move to undo." << endl;
    return false;
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
    //if (playerIsWhite()) cout << "UNDID WHITE MOVE" << endl;
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
    return nullptr;
}

void ChessGame::computerMove() { // By Megan Samn, edited by Adolfo Bugarin
    swapPlayer();
    if (!playerInMate()) {
        srand(time(0) + randomSeed++);

        int randomLoc = rand() % 64 + 1;
        int randomDest = rand() % 64 + 1;                    
        ChessPiece* randomPiece = theBoard->getPiece(randomLoc);  

        bool needMove = true;
        bool randomMove = true;
        while (needMove) {
            while (!randomPiece || currentPlayer != randomPiece->white || !randomPiece->canMove(theBoard->sendBoard(), randomDest)) { 
                randomLoc = rand() % 64 + 1;            
                randomDest = rand() % 64 + 1;                           
                randomPiece = theBoard->getPiece(randomLoc);   
            }
            if (canCheck()) randomMove = false;
            else move(randomLoc, randomDest);

            if (playerInCheck()) {
                undo();
                randomPiece = nullptr;
            }
            else needMove = false;

            if (canPromote()) {
                if (rand() % 2 == 0) promotePawn(5); // Promotes to queen
                else promotePawn(2); // Promotes to knight
            }
        }
        if (randomMove) {
            cout << "RANDOM COMPUTER MOVE: ";
            announceMove(randomLoc, randomDest);
        }
    }
    swapPlayer();
}   

bool ChessGame::canCheck() {
    vector<int> checkMoves;
    int l, d;
    for (l = 1; l < 65; l++) {
        for (d = 1; d < 65; d++)
            if (move(l, d)) {
                if (theBoard->getPiece(d)->white == playerIsWhite() && !playerInCheck()) 
                    if (playerIsWhite() && theBoard->blackInCheck() || !playerIsWhite() && theBoard->whiteInCheck()) {
                        checkMoves.push_back(l);
                        checkMoves.push_back(d);
                    }
                undo();
            }
    }
    if (checkMoves.size() > 0) {
        int i = rand() % checkMoves.size();
        if (i % 2 == 1) i--;
        l = checkMoves.at(i);
        d = checkMoves.at(++i);

        move(l, d);
        cout << "PLANNED COMPUTER MOVE: ";
        announceMove(l, d);
        return true;
    }
    return false;
}

bool ChessGame::whiteMate() {
    if (onlyKings()) return true;
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
    if (onlyKings()) return true;
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

void ChessGame::printBoard() {
    if (playerIsWhite()) theBoard->printBoardWhite();
    else theBoard->printBoardBlack();
}

void ChessGame::swapPlayer() {
    if (playerIsWhite()) setPlayerBlack();
    else setPlayerWhite();
}

bool ChessGame::playerInCheck() {
    if (playerIsWhite()) return theBoard->whiteInCheck();
    else return theBoard->blackInCheck();
}

bool ChessGame::playerInMate() {
    if (playerIsWhite()) return whiteMate();
    else return blackMate();
}

bool ChessGame::sameColor(int l) {
    if (theBoard->getPiece(l) && currentPlayer == theBoard->getPiece(l)->white)
        return true;
    return false;
}

void ChessGame::announceMove(int l, int d) {
    announce(l);
    if (moveLog.top() != 0) cout << "x "; // Only outputs an 'x' if a piece was captured in the last move
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

void ChessGame::announceCheck() {
    if (theBoard->whiteInCheck()) cout << "WHITE CHECK!" << endl;
    if (theBoard->blackInCheck()) cout << "BLACK CHECK!" << endl;
}

int ChessGame::announceMate() {
    if (onlyKings()) {
        cout << "STALEMATE" << endl;
        printBoard();
        cout << "Good game!" << endl;
        return 0;
    }
    int result;
    if (whiteMate()) {
        if (theBoard->whiteInCheck()) {
            cout << "WHITE CHECKMATE" << endl;
            result = 1;
        } else {
            cout << "WHITE STALEMATE" << endl;
            result = 2;
        }
        printBoard();
        cout << "Good game!" << endl;
        return result;
    }
    if (blackMate()) {
        if (theBoard->blackInCheck()) {
            cout << "BLACK CHECKMATE" << endl;
            result = 3;
        } else {
            cout << "BLACK STALEMATE" << endl;
            result = 4;
        }
        printBoard();
        cout << "Good game!" << endl;
        return result;
    }
    return -1;
}

bool ChessGame::onlyKings() {
    for (int i = 1; i < 65; i++)
        if (theBoard->getPiece(i) && theBoard->getPiece(i)->id != 6)
            return false;
    return true;
}

bool ChessGame::canPromote() { // By Justin Chen
    for (int i = 1; i < 65; i++) {
 	    int row = i / 8;
        if (i % 8 != 0) {
            row += 1;
        }
        if (theBoard->getPiece(i) && theBoard->getPiece(i)->id == 1 && (row == 1 || row == 8)) {
            return true;
        }
    }
    return false;
 }

 void ChessGame::promotePawn(int pieceType) { // By Justin Chen
    ChessPiece* tempPiece = retrievePiece(pieceType);
    for (int l = 1; l < 65; l++) {
        int row = l / 8;
        if (l % 8 != 0) {
            row += 1;
        }
        if (theBoard->getPiece(l) && theBoard->getPiece(l)->id == 1 && (row == 1 || row == 8)) {
            bool color = true;
            if (!theBoard->getPiece(l)->white) {
                color = false;
            }
            delete theBoard->getPiece(l);
            l = trans(l);
            theBoard->sendBoard()[l] = tempPiece;
            tempPiece->location = l;
            tempPiece->white = color;
        }
    }
 }
