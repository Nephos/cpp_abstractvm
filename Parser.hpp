#ifndef PARSER_HPP
# define PARSER_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <map>
# include <vector>

# include "IOperand.hpp"
# include "MutantStack.hpp"
# include "Exceptions.hpp"

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
  void		initIO(const std::string &);
  void		initIO();
  void		executeInstruction(const std::string &);

private:
  void		push(IOperand *);
  void		assert(IOperand *);
  void		pop();
  void		dump();
  void		add();
  void		sub();
  void		mul();
  void		div();
  void		mod();
  void		print();
  void		exit();

  MutantStack<IOperand *> *_mutantStack;
  std::istream *_is;

  std::vector<void (Parser::*)(void)> _ptr0;
  std::vector<void (Parser::*)(IOperand *)> _ptr1;

  std::map<std::string, unsigned int> _instructions;
  std::map<std::string, eArgumentType> _arguments;
};

#endif
