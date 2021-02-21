#include <iostream>
#include <new>
#include <string>

#include "../header/engine.h"
#include "../header/uci.h"


int main(void) {
  std::string input;
  Engine engine = Engine();

  while (true) {
    std::getline(std::cin, input);
    if (UCI::respond(input, engine)) {
      return 0;
    }
  }
}
