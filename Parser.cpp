#include "Parser.hpp"

Parser::Parser() {
}

Parser::~Parser() {
  std::ifstream *tmp;
  if ((tmp = dynamic_cast<std::ifstream *>(is))) {
    // A CHANGER
    if (!tmp)
      throw 1;
    tmp->close();
    delete is;
  }
}

Parser::Parser(const Parser &) {
}

void		Parser::parse()
{
  char buffer[BUFF_SIZE];

  while (is->getline(buffer, BUFF_SIZE)) {
    std::cout << buffer << std::endl;
  }
}

void		Parser::initIO(const std::string& filename)
{
  std::ifstream * ifs = new std::ifstream(filename.data());
  if (!ifs->is_open())
    return;
  is = ifs;
  //throw
}

void		Parser::initIO()
{
  is = &std::cin;
}
