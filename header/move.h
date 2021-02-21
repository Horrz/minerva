#pragma once

#include <string>
#include "../header/definitions.h"

class Move {
  public:
	Move(Square from, Square to);
  Move(Square from, Square to, Piece promoteTo);
  ~Move();
  std::string toString();

  private:
  Square m_from;
  Square m_to;
  Piece m_promoteTo;
};