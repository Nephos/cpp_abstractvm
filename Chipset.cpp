#include "Chipset.hpp"

Chipset::Chipset(VirtualCPU * const cpu) : _cpu(cpu) {
  _instructions["push"] =	1;
  _instructions["pop"] =	0;
  _instructions["dump"] =	0;
  _instructions["assert"] =	1;
  _instructions["assert_eq"] =	1;
  _instructions["assert_not"] =	1;
  _instructions["assert_gt"] =	1;
  _instructions["assert_lt"] =	1;
  _instructions["assert_get"] =	1;
  _instructions["assert_let"] =	1;
  _instructions["assert_type"] = 1;
  _instructions["assert_not_type"] = 1;
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
  _argumentsTypes["int8"] =	Int8;
  _argumentsTypes["int16"] =	Int16;
  _argumentsTypes["int32"] =	Int32;
  _argumentsTypes["float"] =	Float;
  _argumentsTypes["double"] =	Double;
  _is = NULL;
}

Chipset::~Chipset()
{
  std::ifstream *tmp;
  if ((tmp = dynamic_cast<std::ifstream *>(_is))) {
    if (tmp) {
      tmp->close();
      delete _is;
    }
  }
}

Chipset::Chipset(const Chipset &) {
}

void		Chipset::parse_debug()
{
  char buffer[BUFF_SIZE];
  int exited = 0;
  size_t line = 0;
  while (_is->getline(buffer, BUFF_SIZE)) {
    line++;
    if (_is == &std::cin && std::string(buffer).find(";;") == 0)
      break;
    try {
      exited |= executeLine(buffer);
    }
    catch (VMException &e) {
      e.setLine(line);
      e.setFile(_filename);
      std::cout << e.what() << std::endl;
    }
  }
  try {
    if (!exited)
      throw NoExitException("Missing exit instruction");
  }
  catch (VMException &e) {
    e.setFile(_filename);
    std::cout << e.what() << std::endl;
  }
}

void		Chipset::parse()
{
  char buffer[BUFF_SIZE];
  int exited = 0;
  size_t line = 0;
  std::vector<std::string> exceptions;
  std::vector<std::string> lines;
  while (_is->getline(buffer, BUFF_SIZE)) {
    line++;
    lines.push_back(buffer);
    if (_is == &std::cin && std::string(buffer).find(";;") == 0)
      break;
    try {
      exited |= executeLine(buffer, true);
    }
    catch (VMException &e) {
      e.setLine(line);
      e.setFile(_filename);
      exceptions.push_back(e.what());
    }
  }
  try {
    if (!exited)
      throw NoExitException("Missing exit instruction");
  }
  catch (VMException &e) {
    e.setFile(_filename);
    exceptions.push_back(e.what());
  }

  std::vector<std::string>::iterator it;
  std::vector<std::string>::iterator itend;
  if (not exceptions.empty()) {
      it = exceptions.begin();
      itend = exceptions.end();
      for (; it != itend; it++)
	std::cerr << std::string(*it) << std::endl;
    }
  else {
      it = lines.begin();
      itend = lines.end();
      for (; it != itend; it++)
	executeLine((*it));
    }
}


void		Chipset::initIO(const std::string& filename) {
  std::ifstream * ifs = new std::ifstream(filename.data());
  if (!ifs->is_open())
    throw IOException(std::string("Unable to open ") + filename);
  _is = ifs;
  _filename = filename;
}

void		Chipset::initIO() {
  _is = &std::cin;
  _filename = "stdin";
}

int			Chipset::executeLine(const std::string & line, bool only_parse)
{
  std::stringstream	s;
  std::string		instruct;
  std::map<std::string, nb_arguments>::iterator iti;
  std::map<std::string, eArgumentType>::iterator ita;
  std::map<std::string, eOperandType>::iterator itt;
  std::vector<eOperandType>	args_type;
  std::vector<std::string>	args_value;
  std::string			arg_value;

  s << line;
  s >> instruct;
  if (instruct.empty() || instruct[0] == ';')
    return 0;
  iti = _instructions.find(instruct); // iti contains a number of arguments
  if (iti == _instructions.end())
    throw SyntaxException(std::string("instruction ") + s.str() + " not found");

  for (nb_arguments i = iti->second; i > 0; i--) {
      std::size_t token1, token2;
      std::string arg_str;

      s >> arg_str;
      if (arg_str.empty())
	throw SyntaxException(std::string("Missing argument for ") + instruct);

      token1 = arg_str.find('(');
      if (token1 == std::string::npos)
	throw SyntaxException(std::string("Unable to find value for ") + arg_str);

      // arg_str.substr(0, token1) == "int8" ...
      ita = _arguments.find(arg_str.substr(0, token1)); // ita contains eArgumentType
      if (ita == _arguments.end())
	throw SyntaxException(std::string("No type found (") + arg_str.substr(0, token1) + ")");
      itt = _argumentsTypes.find(arg_str.substr(0, token1)); // itt contains eOperandType

      token2 = arg_str.find(')');
      if (token2 == std::string::npos)
	throw SyntaxException(std::string("Unable to find value for ") + arg_str);

      // arg_str.substr(token1 + 1, token2 - token1 - 1) == "42"
      arg_value = arg_str.substr(token1 + 1, token2 - token1 - 1);
      if (!arg_value.empty() && arg_value[0] == '0' && arg_value.find_first_not_of('0') != std::string::npos)
	arg_value = arg_value.substr(arg_value.find_first_not_of('0')); // remove trailling ZERO
      if (arg_value[0] == '.')
	arg_value = "0" + arg_value;
      if ((ita->second == Integer) && (
				       (arg_value.find_first_not_of("-0123456789") != std::string::npos) ||
				       (arg_value.find_last_of("-") != 0 && arg_value.find_last_of("-") != std::string::npos)
				       )
	  )
	throw MalformedNumericException("Malformed Integer Value");
      if ((ita->second == Decimal) && (
				       (arg_value.find_first_not_of("-.0123456789") != std::string::npos) ||
				       (arg_value.find_last_of("-") != 0 && arg_value.find_last_of("-") != std::string::npos)
				       || (arg_value.find_first_of(".") != arg_value.find_last_of("."))
				       || arg_value.find_last_of(".") == std::string::npos)
	  )
	throw MalformedNumericException("Malformed Decimal Value");
      args_type.push_back(itt->second);
      args_value.push_back(arg_value);
    }
  std::string str;
  s >> str;
  if (!str.empty())
    throw SyntaxException(std::string("Too many arguments for ") + instruct + s.str());
  if (only_parse == true)
    {
      if (instruct == "exit")
	return 1;
      return 0;
    }
  else
    return _cpu->executeInstruction(instruct, args_type, args_value);
}
