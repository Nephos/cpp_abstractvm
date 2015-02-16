#include "IOperand.hpp"
#include "Operand.hpp"

int	main()
{
  IOperand	*toto1 = new Operand<char>("0", Int8);
  IOperand	*toto2 = new Operand<char>("1", Int8);
  IOperand	*toto3 = *toto1 + *toto2;

  std::cout << toto3->toString() << std::endl;
  return (0);
}
