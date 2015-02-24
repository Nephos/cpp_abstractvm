#include "IOperand.hpp"
#include "Operand.hpp"
#include "Chipset.hpp"
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
  Chipset chipset(cpu);

  if (argc == 1)
    chipset.initIO();
  else
    chipset.initIO(argv[1]);
  chipset.parse();


  return (0);
}
