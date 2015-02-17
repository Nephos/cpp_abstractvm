#include "VirtualCPU.hpp"

VirtualCPU::VirtualCPU(const MutantStack<IOperand *> * mutantStack) {
  _ptr1.push_back(&VirtualCPU::push);
  _ptr1.push_back(&VirtualCPU::assert);
  _ptr0.push_back(&VirtualCPU::pop);
  _ptr0.push_back(&VirtualCPU::dump);
  _ptr0.push_back(&VirtualCPU::add);
  _ptr0.push_back(&VirtualCPU::sub);
  _ptr0.push_back(&VirtualCPU::mul);
  _ptr0.push_back(&VirtualCPU::div);
  _ptr0.push_back(&VirtualCPU::mod);
  _ptr0.push_back(&VirtualCPU::print);
  _ptr0.push_back(&VirtualCPU::exit);
  VirtualCPU::_ptrToOperand[0] = &VirtualCPU::createInt8;
  VirtualCPU::_ptrToOperand[1] = &VirtualCPU::createInt16;
  VirtualCPU::_ptrToOperand[2] = &VirtualCPU::createInt32;
  VirtualCPU::_ptrToOperand[3] = &VirtualCPU::createFloat;
  VirtualCPU::_ptrToOperand[4] = &VirtualCPU::createDouble;
}

VirtualCPU::~VirtualCPU() {
  
}

void            VirtualCPU::push(IOperand *elem) {
  _mutantStack->push(elem);
}

void            VirtualCPU::assert(IOperand *elem) {
  // Changer le throw avec une xception
  if (elem->toString() != _mutantStack->top()->toString())
    throw 1;
}

void            VirtualCPU::pop() {
  // Throw error if stack is empty
  _mutantStack->pop();
}

void            VirtualCPU::dump() {
  // MutantStack<IOperand *>::iterator *it(&_mutantStack->begin());
  // MutantStack<IOperand *>::iterator *itend(&_mutantStack->end());

  // while (it != itend) {
  //   std::cout << it->toString() << std::endl;
  //   ++it;
  // }
  
}

void            VirtualCPU::add() {
  // Throw if stack size < 2 
  IOperand *first = _mutantStack->top();
  _mutantStack->pop();
  IOperand *second = _mutantStack->top();
  _mutantStack->pop();
  _mutantStack->push(*first + *second);
}

void            VirtualCPU::sub() {
  // Throw if stack size < 2 
  IOperand *first = _mutantStack->top();
  _mutantStack->pop();
  IOperand *second = _mutantStack->top();
  _mutantStack->pop();
  _mutantStack->push(*first - *second);
}

void            VirtualCPU::mul() {
  // Throw if stack size < 2 
  IOperand *first = _mutantStack->top();
  _mutantStack->pop();
  IOperand *second = _mutantStack->top();
  _mutantStack->pop();
  _mutantStack->push(*first * *second);
}

void            VirtualCPU::div() {
  // Throw if stack size < 2
  // Throw if divisor is 0
  IOperand *first = _mutantStack->top();
  _mutantStack->pop();
  IOperand *second = _mutantStack->top();
  _mutantStack->pop();
  _mutantStack->push(*first / *second);
}

void            VirtualCPU::mod() {
  // Throw if stack size < 2
  // Throw if divisor is 0
  IOperand *first = _mutantStack->top();
  _mutantStack->pop();
  IOperand *second = _mutantStack->top();
  _mutantStack->pop();
  _mutantStack->push(*first % *second);
}

void            VirtualCPU::print() {
  // Changer le Throw
  if (_mutantStack->top()->getType() != Int8)
    throw 1;
  std::stringstream ss;
  ss << _mutantStack->top();
  std::cout << ss.str() << std::endl;
}

void            VirtualCPU::exit() {
}

void		VirtualCPU::executeInstruction(const std::string & instruction, const std::string) {
  
}

IOperand *	VirtualCPU::createOperand(eOperandType type, const std::string & value) {
  return (this->*_ptrToOperand[type])(value);
}

IOperand *	VirtualCPU::createInt8(const std::string & value) {
  return new Operand<char>(value, Int8);
}

IOperand *	VirtualCPU::createInt16(const std::string & value) {
  return new Operand<short>(value, Int16);
}

IOperand *	VirtualCPU::createInt32(const std::string & value) {
  return new Operand<int>(value, Int32);
}

IOperand *	VirtualCPU::createFloat(const std::string & value) {
  return new Operand<float>(value, Float);
}

IOperand *	VirtualCPU::createDouble(const std::string & value) {
  return new Operand<double>(value, Double);
}


