#include "Parser.hpp"

Parser::Parser() {
}

Parser::~Parser() {
  if (dynamic_cast<std::ifstream *>(is))
    delete is;
}

Parser::Parser(const Parser &) {
}

void		Parser::parse()
{
  char buffer[BUFF_SIZE];

  is->getline(buffer, BUFF_SIZE);
  std::cout << buffer << std::endl;
}

void		Parser::loadFile(const std::string& filename)
{
  if (filename.empty())
    is = &std::cin;
  else {
    is = new std::ifstream;
    if (!is->good())
      return;
    //throw
  }
}
