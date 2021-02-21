#pragma once

#include <vector>

#include "../header/definitions.h"
#include "../header/move.h"

class Chess {
public:
  Chess();
  ~Chess();
  std::vector<Move> generateMoves();
  void makeMove(Move);

private:
  Piece m_board[SquareCount] {
    Rook,  Knight, Bishop, Queen, King,  Bishop, Knight, Rook,
    Pawn,  Pawn,   Pawn,   Pawn,  Pawn,  Pawn,   Pawn,   Pawn,
    empty, empty,  empty,  empty, empty, empty,  empty,  empty,
    empty, empty,  empty,  empty, empty, empty,  empty,  empty,
    empty, empty,  empty,  empty, empty, empty,  empty,  empty,
    empty, empty,  empty,  empty, empty, empty,  empty,  empty,
    pawn,  pawn,   pawn,   pawn,  pawn,  pawn,   pawn,   pawn,
    rook,  knight, bishop, queen, king,  bishop, knight, rook,
  };

  int m_drawPlyCounter { 0 };
  Player m_playerToMove { White };
  // whiteQueenSide, whiteKingSide, blackQueenSide, blackKingSide
  int m_possibleCastles { 0b1111 };
  bool m_enPassent { 0 };

private:
  void pawnMove(Square square, std::vector<Move>& moves);
  void knightMove(Square square, std::vector<Move>& moves);
  void bishopMove(Square square, std::vector<Move>& moves);
  void rookMove(Square square, std::vector<Move>& moves);
  void queenMove(Square square, std::vector<Move>& moves);
  void kingMove(Square square, std::vector<Move>& moves);

  bool isBackRank(int y);
  bool is2ndRank(int y);
  bool isEmpty(Square square);
  bool isOpponents(Square square);
};
