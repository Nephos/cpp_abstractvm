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

  MutantStack<IOperand *> mutantStack;
  VirtualCPU *cpu = new VirtualCPU(&mutantStack);

  try {
    if (argc == 1)
      {
	Chipset chipset(cpu);
	chipset.initIO();
#ifdef DEBUG_MODE
	chipset.parse_debug();
#else
	chipset.parse();
#endif
      }
    else
      for (int i = 1; i < argc; i++)
	{
	  Chipset chipset(cpu);
	  chipset.initIO(argv[i]);
#ifdef DEBUG_MODE
	  chipset.parse_debug();
#else
	  chipset.parse();
#endif
	}
  }
  catch (VMException &e) {
    std::cout << e.what() << std::endl;
  }
  return (0);
}
