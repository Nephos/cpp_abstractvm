#ifndef CHIPSET_HPP
# define CHIPSET_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <map>
# include <vector>
# include <algorithm>
# include <string>

# include "VirtualCPU.hpp"
# include "IOperand.hpp"
# include "Exceptions.hpp"

# define BUFF_SIZE 50000

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
  void		parse_debug();
  void		initIO(const std::string &);
  void		initIO();
  int		executeLine(const std::string &, bool only_parse = false);

private:
  std::istream *_is;
  std::string _filename;
  VirtualCPU * _cpu;

  std::map<std::string, nb_arguments> _instructions;
  std::map<std::string, eArgumentType> _arguments;
  std::map<std::string, eOperandType> _argumentsTypes;
};

#endif
