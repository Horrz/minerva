#include <assert.h>
#include "../header/chess.h"
#include <iostream>
#include <iterator>
#include <ostream>
#include <vector>

Chess::Chess() {}
Chess::~Chess() {}

bool Chess::isBackRank(int y) {
  return (m_playerToMove == White && y == 7) || (m_playerToMove == Black && y == 0);
}
bool Chess::is2ndRank(int y) {
    return (m_playerToMove == White && y == 1) || (m_playerToMove == Black && y == 6);
}
bool Chess::isEmpty(Square square) {
  return isInbounds(square) && m_board[square] == 0;
} 
bool Chess::isOpponents(Square square) {
  return m_board[square] * m_playerToMove < 0;
}

void Chess::pawnMove(Square square, std::vector<Move>& moves) {
  // move 1 field
  Square nextSquare = static_cast<Square>(square + m_playerToMove * 8);
  if(isEmpty(nextSquare)) {
    if (isBackRank(nextSquare)) {
      moves.push_back(Move(square, nextSquare, Knight));
      moves.push_back(Move(square, nextSquare, Bishop));
      moves.push_back(Move(square, nextSquare, Rook));
      moves.push_back(Move(square, nextSquare, Queen));
    } else {
      moves.push_back(Move(square, nextSquare));
    }
    // move 2 fields
    if (is2ndRank(GetRank(square))) {
      Square nextNextSquare = static_cast<Square>(nextSquare + m_playerToMove * 8);
      if(isEmpty(nextNextSquare)) {
        moves.push_back(Move(square, nextNextSquare));
      }
    }
  }
  
  // TODO capture
  // TODO en passant
}
  
void Chess::knightMove(Square square, std::vector<Move>& moves) {
}

void Chess::bishopMove(Square square, std::vector<Move>& moves) {
}

void Chess::rookMove(Square square, std::vector<Move>& moves) {
}

void Chess::queenMove(Square square, std::vector<Move>& moves) {
  bishopMove(square, moves);
  rookMove(square, moves);
}

void Chess::kingMove(Square square, std::vector<Move>& moves) {
}

std::vector<Move> Chess::generateMoves() {
  std::vector<Move> moves;
  for(char i=0; i<SquareCount; i++) {
    Square square = static_cast<Square>(i);
    // multiplication with m_toMove, checks for current player
    int piece = m_board[i] * m_playerToMove;
    // fixme oop
    switch (piece) {
      case Pawn:
        pawnMove(square, moves);
        continue;
      case Knight:
        knightMove(square, moves);
        continue;
      case Bishop:
        bishopMove(square, moves);
        continue;
      case Rook:
        rookMove(square, moves);
        continue;
      case Queen:
        queenMove(square, moves);
        continue;
      case King:
        kingMove(square, moves);
        continue;
    }
  }

  //// only for debug
  //for (int i=0; i<moves.size(); i++) {
  //  std::cout << moves.at(i).toString() << std::endl;
  //}
  return moves;
}
