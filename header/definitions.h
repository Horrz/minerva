#pragma once

enum Player : char {
  White = 1,
  Black = -1,
};

enum Piece : char {
  // empty
  empty = 0,

  // white pieces
  Pawn = 1,
  Knight = 2,
  Bishop = 3,
  Rook = 4,
  Queen = 5,
  King = 6,

  // black pieces
  pawn = -Pawn,
  knight = -Knight,
  bishop = -Bishop,
  rook = -Rook,
  queen = -Queen,
  king = -King,
};

enum Square : char {
  A1, B1, C1, D1, E1, F1, G1, H1,
  A2, B2, C2, D2, E2, F2, G2, H2,
  A3, B3, C3, D3, E3, F3, G3, H3,
  A4, B4, C4, D4, E4, F4, G4, H4,
  A5, B5, C5, D5, E5, F5, G5, H5,
  A6, B6, C6, D6, E6, F6, G6, H6,
  A7, B7, C7, D7, E7, F7, G7, H7,
  A8, B8, C8, D8, E8, F8, G8, H8,

  SquareCount
};

constexpr char GetRank(Square square) {
  return square / 8;
}

constexpr char GetFile(Square square) {
  return square % 8;
}

constexpr bool isInbounds(Square square) {
  return square < SquareCount;
}
