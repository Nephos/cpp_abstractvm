#ifndef VIRTUALCPU_H_
# define VIRTUALCPU_H_

#include <map>
#include <vector>
#include <sstream>

#include "MutantStack.hpp"
#include "Operand.hpp"

class VirtualCPU {
public:
  VirtualCPU(MutantStack<IOperand *> *);
  ~VirtualCPU();

  int          pop(IOperand *);
  int          pop();
  IOperand     *top();

  int          push(IOperand *);
  int          assert(IOperand *);
  int          assert_eq(IOperand *);
  int          assert_not(IOperand *);
  int          assert_gt(IOperand *);
  int          assert_lt(IOperand *);
  int          assert_get(IOperand *);
  int          assert_let(IOperand *);
  int          assert_type(IOperand *);
  int          assert_not_type(IOperand *);
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
