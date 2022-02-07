#include "ChessBoard.hpp"

ChessBoard::ChessBoard() {
    board = new ChessSquare[64];
    newBoard();
}

ChessBoard::~ChessBoard() {
    for(int i = 0; i < 64; i++)
        if(board[i].piece != nullptr)
            delete board[i].piece;
}

void ChessBoard::newBoard() {
    board[0].piece = new Rook;  // Sets up white pieces
    board[1].piece = new Knight;
    board[2].piece = new Bishop;
    board[3].piece = new Queen;
    board[4].piece = new King;
    board[5].piece = new Bishop;
    board[6].piece = new Knight;
    board[7].piece = new Rook;
    for(int i = 8; i < 16; i++)
        board[i].piece = new Pawn;
    for(int i = 0; i < 16; i++)
        board[i].piece->white = false;

    for(int i = 48; i < 56; i++)    // Sets up black pieces
        board[i].piece = new Pawn;
    board[56].piece = new Rook;
    board[57].piece = new Knight;
    board[58].piece = new Bishop;
    board[59].piece = new Queen;
    board[60].piece = new King;
    board[61].piece = new Bishop;
    board[62].piece = new Knight;
    board[63].piece = new Rook;
    for(int i = 48; i < 64; i++) 
        board[i].piece->white = true;
}

void ChessBoard::printBoard() {
    int row = 8;
    for(int i = 0; i < 64; i++) {
        if((i + 8) % 8 == 0) {cout << row << ' '; row--;}
        if(board[i].piece == nullptr) cout << "· ";
        else cout << board[i].piece->getPiece() << ' ';
        if((i + 1) % 8 == 0) cout << endl;
    }
    cout << "  a b c d e f g h " << endl;
}
