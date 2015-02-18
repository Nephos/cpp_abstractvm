#include "VirtualCPU.hpp"

VirtualCPU::VirtualCPU(const MutantStack<IOperand *> * mutantStack) {
  _ptr["push"] = (&VirtualCPU::push);
  _ptr["assert"] = (&VirtualCPU::assert);
  _ptr["pop"] = (&VirtualCPU::pop);
  _ptr["dump"] = (&VirtualCPU::dump);
  _ptr["add"] = (&VirtualCPU::add);
  _ptr["sub"] = (&VirtualCPU::sub);
  _ptr["mul"] = (&VirtualCPU::mul);
  _ptr["div"] = (&VirtualCPU::div);
  _ptr["mod"] = (&VirtualCPU::mod);
  _ptr["print"] = (&VirtualCPU::print);
  _ptr["exit"] = (&VirtualCPU::exit);
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
  if (elem->toString() != _mutantStack->top()->toString())
    throw AssertException(std::string("Comparaison between (") + elem->toString() + ") and (" + _mutantStack->top()->toString() +  ")");
}

void            VirtualCPU::pop(__attribute__((unused)) IOperand *) {
  pop();
}

void            VirtualCPU::pop() {
  if (_mutantStack->empty())
    throw PopException("Not enough element on the stack");
  _mutantStack->pop();
}

void            VirtualCPU::dump(__attribute__((unused)) IOperand *) {
  MutantStack<IOperand *>::iterator it = _mutantStack->begin();
  MutantStack<IOperand *>::iterator itend = _mutantStack->end();

  while (it != itend) {
    std::cout << (*it)->toString() << std::endl;
    ++it;
  }
}

void            VirtualCPU::add(__attribute__((unused)) IOperand *) {
  IOperand *first = _mutantStack->top();
  pop();
  IOperand *second = _mutantStack->top();
  pop();
  _mutantStack->push(*first + *second);
}

void            VirtualCPU::sub(__attribute__((unused)) IOperand *) {
  IOperand *first = _mutantStack->top();
  pop();
  IOperand *second = _mutantStack->top();
  pop();
  _mutantStack->push(*first - *second);
}

void            VirtualCPU::mul(__attribute__((unused)) IOperand *) {
  IOperand *first = _mutantStack->top();
  pop();
  IOperand *second = _mutantStack->top();
  pop();
  _mutantStack->push(*first * *second);
}

void            VirtualCPU::div(__attribute__((unused)) IOperand *) {
  IOperand *first = _mutantStack->top();
  pop(NULL);
  IOperand *second = _mutantStack->top();
  pop();
  _mutantStack->push(*first / *second);
}

void            VirtualCPU::mod(__attribute__((unused)) IOperand *) {
  IOperand *first = _mutantStack->top();
  pop();
  IOperand *second = _mutantStack->top();
  pop();
  _mutantStack->push(*first % *second);
}

void            VirtualCPU::print(__attribute__((unused)) IOperand *) {
  if (_mutantStack->top()->getType() != Int8)
    throw VMException("You cannot \"print\" a non-int8");
  std::stringstream ss;
  ss << _mutantStack->top();
  std::cout << ss.str();
}

void            VirtualCPU::exit(__attribute__((unused)) IOperand *)
{
}

void		VirtualCPU::executeInstruction(const std::string & instruction,
					       const std::vector<eOperandType> & args_t,
					       const std::vector<std::string> & args_v)
{
  switch (args_v.size())
    {
    case 0:
      (this->*_ptr[instruction])(NULL);
      break;
    case 1:
      (this->*_ptr[instruction])(createOperand(args_t[0], args_v[0]));
      break;
    }
}

IOperand *	VirtualCPU::createOperand(eOperandType type, const std::string & value){
  return (this->*_ptrToOperand[type])(value);
}

IOperand *	VirtualCPU::createInt8(const std::string & value){
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
