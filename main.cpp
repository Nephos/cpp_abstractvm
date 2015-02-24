#include "IOperand.hpp"
#include "Operand.hpp"
#include "Parser.hpp"
#include "MutantStack.hpp"
#include "VirtualCPU.hpp"

int	main(int argc, char **argv)
{
#ifdef DEBUG_MODE
  std::cerr << "DEBUG MODE" << std::endl;
#endif

  // IOperand	*toto1 = new Operand<char>("0", Int8);
  // IOperand	*toto2 = new Operand<char>("1", Int8);
  // IOperand	*toto3 = *toto1 + *toto2;
  // toto3 = *toto3 + *toto2;
  // toto3 = *toto3 + *toto2;
  // toto3 = *toto3 + *toto2;
  // toto3 = *toto3 + *toto2;

  MutantStack<IOperand *> mutantStack;
  VirtualCPU *cpu = new VirtualCPU(&mutantStack);
  Parser parser(cpu);

  if (argc == 1)
    parser.initIO();
  else
    parser.initIO(argv[1]);
  parser.parse();


  return (0);
}
