#include "Parser.hpp"

Parser::Parser() {
  _instructions["push"] =  1;
  _instructions["pop"] =  0;
  _instructions["dump"] =  0;
  _instructions["assert"] = 1;
  _instructions["add"] =  0;
  _instructions["sub"] =  0;
  _instructions["mul"] =  0;
  _instructions["div"] =  0;
  _instructions["mod"] =  0;
  _instructions["print"] =  0;
  _instructions["exit"] =  0;
  _arguments["int8"] =  Integer;
  _arguments["int16"] =  Integer;
  _arguments["int32"] =  Integer;
  _arguments["float"] =  Decimal;
  _arguments["double"] =  Decimal;
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

void		Parser::executeInstruction(const std::string & instruction)
{

}
