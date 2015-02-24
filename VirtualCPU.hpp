#ifndef VIRTUALCPU_H_
# define VIRTUALCPU_H_

#include <map>
#include <vector>

#include "MutantStack.hpp"
#include "Operand.hpp"

class VirtualCPU {
public:
  VirtualCPU(MutantStack<IOperand *> *);
  ~VirtualCPU();

  int          push(IOperand *);
  int          assert(IOperand *);
  int          pop(IOperand *);
  int          pop();
  int          dump(IOperand *);
  int          add(IOperand *);
  int          sub(IOperand *);
  int          mul(IOperand *);
  int          div(IOperand *);
  int          mod(IOperand *);
  int          print(IOperand *);
  int          exit(IOperand *);

  int		executeInstruction(const std::string & instruction,
				   const std::vector<eOperandType> & args_t,
				   const std::vector<std::string> & args_v);

  IOperand *	createOperand(eOperandType type, const std::string & value);
  IOperand *	createInt8(const std::string & value);
  IOperand *	createInt16(const std::string & value);
  IOperand *	createInt32(const std::string & value);
  IOperand *	createFloat(const std::string & value);
  IOperand *	createDouble(const std::string & value);

private:
  MutantStack<IOperand *> *_mutantStack;

  std::map<std::string, int (VirtualCPU::*)(IOperand *)> _ptr;
  IOperand * (VirtualCPU::*_ptrToOperand[5])(const std::string &);
};

#endif
