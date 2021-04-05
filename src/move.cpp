#include <iostream>
#include <string>
#include "../header/move.h"
#include "../header/chess.h"

Move::Move(Square from, Square to) {
  m_from = from;
  m_to = to;
  m_promoteTo = empty;
}

Move::Move(Square from, Square to, Piece promoteTo) {
  m_from = from;
  m_to = to;
  m_promoteTo = promoteTo;
}

Move::~Move() {}

Square Move::getFrom() {
  return m_from;
}

Square Move::getTo(){
  return m_to;
}

Piece Move::getPromoteTo(){
  return m_promoteTo;
}

std::string Move::toNotation() {
	std::string moveNotation = "";
  moveNotation += GetFile(m_from) + 'a';
	moveNotation += GetRank(m_from) + '1';
	moveNotation += GetFile(m_to) + 'a';
	moveNotation += GetRank(m_to) + '1';
  if (m_promoteTo == queen) {
  	moveNotation += 'q';
  }
  if (m_promoteTo == rook) {
    moveNotation += 'r';
  }
  if (m_promoteTo == knight) {
    moveNotation += 'n';
  }
  if (m_promoteTo == bishop) {
    moveNotation += 'b';
  }
	return moveNotation;
}
