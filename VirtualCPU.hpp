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

private:
  MutantStack<IOperand *> *_mutantStack;

  std::vector<void (VirtualCPU::*)(void)> _ptr0;
  std::vector<void (VirtualCPU::*)(IOperand *)> _ptr1;
};

#endif
