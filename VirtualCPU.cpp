#include "VirtualCPU.hpp"

VirtualCPU::VirtualCPU(MutantStack<IOperand *> * mutantStack) : _mutantStack(mutantStack) {
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

int            VirtualCPU::push(IOperand *elem) {
  _mutantStack->push(elem);
  return 0;
}

int            VirtualCPU::assert(IOperand *elem) {
  if (elem->toString() != _mutantStack->top()->toString())
    throw AssertException(std::string("Comparaison between (") + elem->toString() + ") and (" + _mutantStack->top()->toString() +  ")");
  // +delete item
  return 0;
}

int            VirtualCPU::pop(__attribute__((unused)) IOperand *) {
  pop();
  return 0;
}

int            VirtualCPU::pop() {
  if (_mutantStack->empty())
    throw PopException("Not enough element on the stack");
  _mutantStack->pop();
  return 0;
}

int            VirtualCPU::dump(__attribute__((unused)) IOperand *) {
  MutantStack<IOperand *>::iterator it = _mutantStack->begin();
  MutantStack<IOperand *>::iterator itlast = _mutantStack->last();

  while (itlast != it) {
    std::cout << (*itlast)->toString() << std::endl;
    --itlast;
    if (itlast == it)
      std::cout << (*itlast)->toString() << std::endl;
  }
  return 0;
}

int            VirtualCPU::add(__attribute__((unused)) IOperand *) {
  IOperand *first = _mutantStack->top();
  pop();
  IOperand *second = _mutantStack->top();
  pop();
  _mutantStack->push(*first + *second);
  return 0;
}

int            VirtualCPU::sub(__attribute__((unused)) IOperand *) {
  IOperand *first = _mutantStack->top();
  pop();
  IOperand *second = _mutantStack->top();
  pop();
  _mutantStack->push(*first - *second);
  return 0;
}

int            VirtualCPU::mul(__attribute__((unused)) IOperand *) {
  IOperand *first = _mutantStack->top();
  pop();
  IOperand *second = _mutantStack->top();
  pop();
  _mutantStack->push(*first * *second);
  return 0;
}

int            VirtualCPU::div(__attribute__((unused)) IOperand *) {
  IOperand *first = _mutantStack->top();
  pop(NULL);
  IOperand *second = _mutantStack->top();
  pop();
  _mutantStack->push(*first / *second);
  return 0;
}

int            VirtualCPU::mod(__attribute__((unused)) IOperand *) {
  IOperand *first = _mutantStack->top();
  pop();
  IOperand *second = _mutantStack->top();
  pop();
  _mutantStack->push(*first % *second);
  return 0;
}

int            VirtualCPU::print(__attribute__((unused)) IOperand *) {
  if (_mutantStack->top()->getType() != Int8)
    throw VMException("You cannot \"print\" a non-int8");
  std::stringstream ss;
  ss << _mutantStack->top();
  std::cout << ss.str();
  return 0;
}

int            VirtualCPU::exit(__attribute__((unused)) IOperand *)
{
  return 1;
}

int		VirtualCPU::executeInstruction(const std::string & instruction,
					       const std::vector<eOperandType> & args_t,
					       const std::vector<std::string> & args_v)
{
  switch (args_v.size())
    {
    case 0:
      return (this->*_ptr[instruction])(NULL);
      break;
    case 1:
      return (this->*_ptr[instruction])(createOperand(args_t[0], args_v[0]));
      break;
    }
  return 1;
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
