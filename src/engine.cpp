#include <assert.h>    
#include <cstdlib>
#include <random>

#include "../header/chess.h"
#include "../header/engine.h"

Engine::Engine() {
  m_chess = Chess();
  m_isThinking = false;
}
Engine::~Engine() {}

void Engine::analyze() {
  m_isThinking = true;
  m_moveList = m_chess.generateMoves();
  assert(m_moveList.size() == 16);
}

void Engine::reset() {

}
bool Engine::isThinking() {
  return m_isThinking;
}

std::string Engine::move() {
  assert (m_isThinking);
  
  m_isThinking = false;
  
  return m_moveList.at(rand() % m_moveList.size()).toString();
}
