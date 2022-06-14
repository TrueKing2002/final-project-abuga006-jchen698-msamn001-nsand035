#include "ChessBoard.hpp"

ChessBoard::ChessBoard() {
    board = new ChessPiece*[64];
    newBoard();
}

ChessBoard::~ChessBoard() {
    for (int i = 0; i < 64; i++)
        if (board[i] != nullptr)
            delete board[i];
    delete[] board;
}

void ChessBoard::newBoard() {
    board[0] = new Rook;  // Sets up white pieces
    board[1] = new Knight;
    board[2] = new Bishop;
    board[3] = new King;
    board[4] = new Queen;
    board[5] = new Bishop;
    board[6] = new Knight;
    board[7] = new Rook;
    for (int i = 8; i < 16; i++)
        board[i] = new Pawn;
    for (int i = 0; i < 16; i++) {
        board[i]->white = true;
        board[i]->location = i;
    }
	
    for (int i = 16; i < 48; i++)
        board[i] = nullptr;

    for (int i = 48; i < 56; i++)    // Sets up black pieces
        board[i] = new Pawn;
    board[56] = new Rook;
    board[57] = new Knight;
    board[58] = new Bishop;
    board[59] = new King;
    board[60] = new Queen;
    board[61] = new Bishop;
    board[62] = new Knight;
    board[63] = new Rook;
    for (int i = 48; i < 64; i++) {
        board[i]->white = false;
        board[i]->location = i;
    }
}

void ChessBoard::movePiece(int loc, int dest) {
    loc = trans(loc);
    dest = trans(dest);
    if (board[loc] == nullptr) cout << "WARNING: ATTEMPTING TO MOVE EMPTY SQUARE" << endl;
    else {
        if (board[dest] != nullptr) delete board[dest];
        board[dest] = board[loc];   // Moves piece to new location
        board[dest]->location = dest;   // Sets new piece's location
        board[loc] = nullptr;   // Removes piece from old location
    }
}

bool ChessBoard::whiteInCheck() {
    int kingLocation = -1;
    for (int i = 1; i < 65; i++) 
        if (board[trans(i)] != nullptr && board[trans(i)]->white == true && board[trans(i)]->id == 6) 
            kingLocation = i;

    if (kingLocation == -1) {
	cout << "ERROR: NO WHITE KING FOUND" << endl;
	return true;
    }

    for (int i = 0; i < 64; i++) 
        if (board[i] != nullptr && board[i]->white == false && board[i]->canMove(board, kingLocation))
            return true;
    return false;
}

bool ChessBoard::blackInCheck() {
    int kingLocation = -1;
    for (int i = 1; i < 65; i++) 
        if (board[trans(i)] != nullptr && board[trans(i)]->white == false && board[trans(i)]->id == 6) 
            kingLocation = i; 

    if (kingLocation == -1) {
	cout << "ERROR: NO BLACK KING FOUND" << endl;
	return true;
    } 

    for (int i = 0; i < 64; i++) 
        if (board[i] != nullptr && board[i]->white == true && board[i]->canMove(board, kingLocation))
            return true;
    return false;
}

void ChessBoard::printBoardWhite() {
    cout << endl;
    int row = 8;
    for (int i = 63; i >= 0; i--) {
        if ((i + 1) % 8 == 0) {cout << row << ' '; row--;}
        if (board[i] == nullptr) cout << "· ";
        else cout << board[i]->getPiece() << ' ';
        if (i % 8 == 0) cout << endl;
    }
    cout << "  a b c d e f g h \n" << endl;
}

void ChessBoard::printBoardBlack() {
    cout << endl;
    int row = 1;
    for (int i = 0; i < 64; i++) {
        if ((i + 8) % 8 == 0) {cout << row << ' '; row++;}
        if (board[i] == nullptr) cout << "· ";
        else cout << board[i]->getPiece() << ' ';
        if ((i + 1) % 8 == 0) cout << endl;
    }
    cout << "  h g f e d c b a \n" << endl;
}
