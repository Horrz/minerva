#include <iostream>
#include <iterator>
#include <ostream>
#include <regex> 
#include <string>

#include "../header/engine.h"

namespace minerva {
  void write(const std::string& message) {
    std::cout << message << std::endl;
  }

  void id() {
    write("id name minerva");
    write("id author Martin Horatschek");
  }

  void isready() {
    write("readyok");
  }

  void options() {
    write("");
  }

  void uciok() {
    write("uciok");
  }

  int respond(const std::string& input, minerva::Engine& engine) {
    if (std::regex_match(input, std::regex("isready") )) { 
      isready();
      return 0;
    }

    if (std::regex_match(input, std::regex("uci") )) { 
      id();
      options();
      uciok();
      return 0;
    }
    if (std::regex_match(input, std::regex("ucinewgame") )) { 
      engine.reset();
      return 0;
    }
    if (std::regex_match(input, std::regex("go") )) { 
      engine.analyze();
      return 0;
    }

    if (std::regex_match(input, std::regex("quit") )) {
      engine.stop();
      // shut down the program
      return 1;
    }
    
    std::cerr << "command unknwon: " << input << std::endl;
    return 0;
  }
}