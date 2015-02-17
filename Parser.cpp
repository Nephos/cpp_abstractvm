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
}

Parser::~Parser() {
  std::ifstream *tmp;
  if ((tmp = dynamic_cast<std::ifstream *>(_is))) {
    // A CHANGER
    if (!tmp)
      throw 1;
    tmp->close();
    delete _is;
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
    return;
  _is = ifs;
  //throw
}

void		Parser::initIO() {
  _is = &std::cin;
}
