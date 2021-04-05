#include <assert.h>
#include <iostream>
#include <iterator>
#include <ostream>
#include <regex> 
#include <string>

#include "../header/engine.h"
#include "../header/uci.h"

UCI::UCI() {}

void UCI::write(const std::string& message) {
  std::cout << message << std::endl;
}

void UCI::id() {
  write("id name minerva");
  write("id author Martin Horatschek");
}

void UCI::isready() {
  write("readyok");
}

void UCI::options() {
  write("");
}

void UCI::uciok() {
  write("uciok");
}

int UCI::respond(const std::string& input, Engine& engine) {
  if (std::regex_match(input, std::regex("^isready") )) { 
    isready();
    return 0;
  }

  if (std::regex_match(input, std::regex("^uci") )) { 
    id();
    options();
    uciok();
    return 0;
  }
  if (std::regex_match(input, std::regex("^ucinewgame") )) { 
    engine.reset();
    return 0;
  }

  if (std::regex_match(input, std::regex("^position startpos(.*)") )) { 
    engine.reset();
    std::match_results<std::string::const_iterator> matches;
    std::regex_match(input, matches, std::regex("[a-zA-Z0-9]{4,5}"));
    
    for (size_t i = 0; i < matches.size(); ++i) {
        std::cout << i << ": '" << matches[i].str() << "'\n";
    }

    return 0;
  }

  if (std::regex_match(input, std::regex("^go(.*)") )) { 
    engine.analyze();
    return 0;
  }

  if (std::regex_match(input, std::regex("^stop") )) {
    if (engine.isThinking()) {
      write("bestmove " + engine.move());
    }
    return 0;
  }

  if (std::regex_match(input, std::regex("^quit") )) {
    if (engine.isThinking()) {
      write("bestmove " + engine.move());
    }
    // shut down the program
    return 1;
  }
  
  std::cerr << "command unknwon: " << input << std::endl;
  return 0;
}
