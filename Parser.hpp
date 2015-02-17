#ifndef PARSER_HPP
# define PARSER_HPP

# include <iostream>
# include <fstream>
# include <map>
# include "MutantStack.hpp"

# define BUFF_SIZE 128

enum eArgumentType {Integer, Decimal};

class Parser
{
public:
  Parser();
  ~Parser();
  Parser(const Parser &);
  Parser& operator=(const Parser &);

  void		parse();
  void		loadFile(const std::string &);
  void		executeInstruction(const std::string &);
private:
  MutantStack<std::string> _mutantStack;
  std::istream *is;
  std::map<std::string, unsigned int> _instructions;
  std::map<std::string, eArgumentType> _arguments;
};

#endif
