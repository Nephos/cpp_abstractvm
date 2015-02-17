#ifndef PARSER_HPP
# define PARSER_HPP

# include <iostream>
# include <fstream>
# include "MutantStack.hpp"

# define BUFF_SIZE 128

class Parser
{
public:
  Parser();
  ~Parser();
  Parser(const Parser &);
  Parser& operator=(const Parser &);

  void		parse();
  void		loadFile(const std::string &);
private:
  MutantStack<std::string> _mutantStack;
  std::istream *is;
};

#endif
