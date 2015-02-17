#include "IOperand.hpp"
#include "Operand.hpp"
#include "Parser.hpp"

int	main(int argc, char **argv)
{
  // IOperand	*toto1 = new Operand<char>("0", Int8);
  // IOperand	*toto2 = new Operand<char>("1", Int8);
  // IOperand	*toto3 = *toto1 + *toto2;
  // toto3 = *toto3 + *toto2;
  // toto3 = *toto3 + *toto2;
  // toto3 = *toto3 + *toto2;
  // toto3 = *toto3 + *toto2;
  Parser parser;

  if (argc == 1)
    parser.initIO();
  else
    parser.initIO(argv[1]);
  parser.parse();
  return (0);
}
