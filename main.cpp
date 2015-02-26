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

  if (argc == 1)
    {
      Chipset chipset(cpu);
      chipset.initIO();
      chipset.parse();
    }
  else
    for (int i = 1; i < argc; i++)
      {
	Chipset chipset(cpu);
	chipset.initIO(argv[i]);
	chipset.parse();
      }
  return (0);
}
