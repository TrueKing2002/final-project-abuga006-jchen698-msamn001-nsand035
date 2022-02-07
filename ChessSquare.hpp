#ifndef CHESSSQUARE
#define CHESSSQUARE

#include "Pawn.cpp"
#include "Knight.cpp"
#include "Bishop.cpp"
#include "Rook.cpp"
#include "Queen.cpp"
#include "King.cpp"
  
class ChessSquare {
    public: ChessPiece *piece = nullptr;
};

#endif
