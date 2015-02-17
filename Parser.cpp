#include "Parser.hpp"

Parser::Parser() {
  _instructions["push"] =	1;
  _instructions["pop"] =	0;
  _instructions["dump"] =	0;
  _instructions["assert"] =	1;
  _instructions["add"] =	0;
  _instructions["sub"] =	0;
  _instructions["mul"] =	0;
  _instructions["div"] =	0;
  _instructions["mod"] =	0;
  _instructions["print"]	0;
  _instructions["exit"] =	0;
  _arguments["int8"] =		Integer;
  _arguments["int16"] =		Integer;
  _arguments["int32"] =		Integer;
  _arguments["float"] =		Decimal;
  _arguments["double"] =	Decimal;
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

void			Parser::executeInstruction(const std::string & instruction)
{
  std::stringstream	s;
  std::map<std::string, unsigned int>::iterator it;

  s << instruction;
  it = _instructions.find(s.str());
  if (it == _instructions.end())
    throw ParseException(std::string("instruction ") + s.str() + " not found");
  s.clear();
}
