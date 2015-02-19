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

  void          push(IOperand *);
  void          assert(IOperand *);
  void          pop(IOperand *);
  void          pop();
  void          dump(IOperand *);
  void          add(IOperand *);
  void          sub(IOperand *);
  void          mul(IOperand *);
  void          div(IOperand *);
  void          mod(IOperand *);
  void          print(IOperand *);
  void          exit(IOperand *);

  void		executeInstruction(const std::string & instruction,
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

  std::map<std::string, void (VirtualCPU::*)(IOperand *)> _ptr;
  IOperand * (VirtualCPU::*_ptrToOperand[5])(const std::string &);
};

#endif
