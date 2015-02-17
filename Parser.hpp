#ifndef PARSER_HPP
# define PARSER_HPP

# include <iostream>
# include <fstream>
# include <vector>

# include "MutantStack.hpp"
# include "IOperand.hpp"

# define BUFF_SIZE 128

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

  // void (*ptr1[2])(IOperand *);
  std::vector<void (Parser::*)(void)> _ptr0;
  std::vector<void (Parser::*)(IOperand *)> _ptr1;
};

#endif
