#ifndef PARSER_HPP
# define PARSER_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <map>
# include <vector>

# include "VirtualCPU.hpp"
# include "IOperand.hpp"
# include "Exceptions.hpp"

# define BUFF_SIZE 128

enum eArgumentType {Integer, Decimal};
typedef unsigned int nb_arguments;

class Parser
{
public:
  Parser(VirtualCPU * const cpu);
  ~Parser();
  Parser(const Parser &);
  Parser& operator=(const Parser &);

  void		parse();
  void		initIO(const std::string &);
  void		initIO();
  void		executeLine(const std::string &);

private:
  IOperand *createOperand(eOperandType, const std::string &);
  std::istream *_is;
  VirtualCPU * _cpu;

  std::map<std::string, nb_arguments> _instructions;
  std::map<std::string, eArgumentType> _arguments;
};

#endif
