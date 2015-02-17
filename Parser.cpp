#include "Parser.hpp"

Parser::Parser() {
  _ptr1.push_back(&Parser::push);
  _ptr1.push_back(&Parser::assert);
  _ptr0.push_back(&Parser::pop);
  _ptr0.push_back(&Parser::dump);
  _ptr0.push_back(&Parser::add);
  _ptr0.push_back(&Parser::sub);
  _ptr0.push_back(&Parser::mul);
  _ptr0.push_back(&Parser::div);
  _ptr0.push_back(&Parser::mod);
  _ptr0.push_back(&Parser::print);
  _ptr0.push_back(&Parser::exit);
  _instructions["push"] =	1;
  _instructions["pop"] =	0;
  _instructions["dump"] =	0;
  _instructions["assert"] =	1;
  _instructions["add"] =	0;
  _instructions["sub"] =	0;
  _instructions["mul"] =	0;
  _instructions["div"] =	0;
  _instructions["mod"] =	0;
  _instructions["print"] =	0;
  _instructions["exit"] =	0;
  _arguments["int8"] =		Integer;
  _arguments["int16"] =		Integer;
  _arguments["int32"] =		Integer;
  _arguments["float"] =		Decimal;
  _arguments["double"] =	Decimal;
}

Parser::~Parser() {
  std::ifstream *tmp;
  if ((tmp = dynamic_cast<std::ifstream *>(_is))) {
    if (tmp) {
      tmp->close();
      delete _is;
    }
  }
}

Parser::Parser(const Parser &) {
}

void		Parser::push(IOperand *elem) {
  _mutantStack->push(elem);
}

void		Parser::assert(IOperand *elem) {

}

void		Parser::pop()
{
}

void		Parser::dump()
{
}

void		Parser::add()
{
}

void		Parser::sub()
{
}

void		Parser::mul()
{
}

void		Parser::div()
{
}

void		Parser::mod()
{
}

void		Parser::print()
{
}

void		Parser::exit()
{
}

void		Parser::parse() {
  char buffer[BUFF_SIZE];

  while (_is->getline(buffer, BUFF_SIZE)) {

    std::cout << buffer << std::endl;
  }
}

void		Parser::initIO(const std::string& filename) {
  std::ifstream * ifs = new std::ifstream(filename.data());
  if (!ifs->is_open())
    throw IOException(std::string("Unable to open ") + filename);
  _is = ifs;
}

void		Parser::initIO() {
  _is = &std::cin;
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
