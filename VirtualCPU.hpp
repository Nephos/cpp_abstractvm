#ifndef VIRTUALCPU_H_
# define VIRTUALCPU_H_

#include <vector>

#include "MutantStack.hpp"
#include "IOperand.hpp"

class VirtualCPU {
public:
  VirtualCPU();
  ~VirtualCPU();

  void          push(IOperand *);
  void          assert(IOperand *);
  void          pop();
  void          dump();
  void          add();
  void          sub();
  void          mul();
  void          div();
  void          mod();
  void          print();
  void          exit();

  IOperand *	createOperand(eOperandType type, const std::string & value);
  IOperand *	createInt8(const std::string & value);
  IOperand *	createInt16(const std::string & value);
  IOperand *	createInt32(const std::string & value);
  IOperand *	createFloat(const std::string & value);
  IOperand *	createDouble(const std::string & value);

private:
  MutantStack<IOperand *> *_mutantStack;

  std::vector<void (VirtualCPU::*)(void)> _ptr0;
  std::vector<void (VirtualCPU::*)(IOperand *)> _ptr1;
};

#endif
