#pragma once

#include <string>

#include "../header/engine.h"

class UCI {
public:
  static int respond(const std::string& input, Engine& engine);
private:
  UCI();
  static void write(const std::string& message);
  static void id();
  static void isready();
  static void options();
  static void uciok();
};
