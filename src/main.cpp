#include <iostream>
#include <string>

#include "../header/engine.h"
#include "../header/uci.h"


int main(void) {
  std::string input;
  minerva::Engine engine;

  while (true) {
    std::getline(std::cin, input);
    if (minerva::respond(input, engine)) {
      return 0;
    }
  }
}
