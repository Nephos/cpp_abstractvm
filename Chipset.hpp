#ifndef CHIPSET_HPP
# define CHIPSET_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <map>
# include <vector>
# include <algorithm>

# include "VirtualCPU.hpp"
# include "IOperand.hpp"
# include "Exceptions.hpp"

# define BUFF_SIZE 512

enum eArgumentType {Integer, Decimal};
typedef unsigned int nb_arguments;

class Chipset
{
public:
  Chipset(VirtualCPU * const cpu);
  ~Chipset();
  Chipset(const Chipset &);
  Chipset& operator=(const Chipset &);

  void		parse();
  void		initIO(const std::string &);
  void		initIO();
  int		executeLine(const std::string &);

private:
  std::istream *_is;
  VirtualCPU * _cpu;

  std::map<std::string, nb_arguments> _instructions;
  std::map<std::string, eArgumentType> _arguments;
  std::map<std::string, eOperandType> _argumentsTypes;
};

#endif
