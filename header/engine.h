#pragma once

#include "../header/chess.h"
#include "../header/move.h"
#include <string>
#include <vector>

class Engine {
  public:
    Engine();
    ~Engine();
    void reset();
    void analyze();
    std::string move();
    bool isThinking();
  private:
    Chess m_chess;
    bool m_isThinking;
    // TODO change to Tree for MCTS
    std::vector<Move> m_moveList;
};
