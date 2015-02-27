#include "VirtualCPU.hpp"
#include "std_improve.hpp"

VirtualCPU::VirtualCPU(MutantStack<IOperand *> * mutantStack) : _mutantStack(mutantStack) {
  _ptr["push"] = (&VirtualCPU::push);
  _ptr["assert"] = (&VirtualCPU::assert);
  _ptr["assert_eq"] = (&VirtualCPU::assert_eq);
  _ptr["assert_not"] = (&VirtualCPU::assert_not);
  _ptr["assert_gt"] = (&VirtualCPU::assert_gt);
  _ptr["assert_lt"] = (&VirtualCPU::assert_lt);
  _ptr["assert_get"] = (&VirtualCPU::assert_get);
  _ptr["assert_let"] = (&VirtualCPU::assert_let);
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
  eOperandType accuracy = (elem->getPrecision() > _mutantStack->top()->getPrecision() ? elem->getType() : _mutantStack->top()->getType());
  IOperand *first = createOperand(accuracy, _mutantStack->top()->toString());
  IOperand *second = createOperand(accuracy, elem->toString());
  delete elem;
  if (first->toString() != second->toString())
    {
      std::string what = std::string("Comparaison EQ between (") + first->toString() + ") and (" + second->toString() + ")";
      delete first;
      delete second;
      throw AssertException(what);
    }
  delete first;
  delete second;
  return 0;
}

int		VirtualCPU::assert_eq(IOperand *elem)
{
  return assert(elem);
}

int            VirtualCPU::assert_not(IOperand *elem) {
  eOperandType accuracy = (elem->getPrecision() > _mutantStack->top()->getPrecision() ? elem->getType() : _mutantStack->top()->getType());
  IOperand *first = createOperand(accuracy, _mutantStack->top()->toString());
  IOperand *second = createOperand(accuracy, elem->toString());
  delete elem;
  if (first->toString() == second->toString())
    {
      std::string what = std::string("Comparaison NEQ between (") + first->toString() + ") and (" + second->toString() + ")";
      delete first;
      delete second;
      throw AssertException(what);
    }
  delete first;
  delete second;
  return 0;
}

int            VirtualCPU::assert_gt(IOperand *elem) {
  eOperandType accuracy = (elem->getPrecision() > _mutantStack->top()->getPrecision() ? elem->getType() : _mutantStack->top()->getType());
  IOperand *first = createOperand(accuracy, _mutantStack->top()->toString());
  IOperand *second = createOperand(accuracy, elem->toString());
  delete elem;
  std::stringstream s1, s2;
  double d1, d2;
  s1 << first->toString();
  s1 >> d1;
  s2 << second->toString();
  s2 >> d2;
  if (d1 < d2)
    {
      std::string what = std::string("Comparaison GT between (") + first->toString() + ") and (" + second->toString() + ")";
      delete first;
      delete second;
      throw AssertException(what);
    }
  delete first;
  delete second;
  return 0;
}

int            VirtualCPU::assert_lt(IOperand *elem) {
  eOperandType accuracy = (elem->getPrecision() > _mutantStack->top()->getPrecision() ? elem->getType() : _mutantStack->top()->getType());
  IOperand *first = createOperand(accuracy, _mutantStack->top()->toString());
  IOperand *second = createOperand(accuracy, elem->toString());
  delete elem;
  std::stringstream s1, s2;
  double d1, d2;
  s1 << first->toString();
  s1 >> d1;
  s2 << second->toString();
  s2 >> d2;
  if (d1 > d2)
    {
      std::string what = std::string("Comparaison LT between (") + first->toString() + ") and (" + second->toString() + ")";
      delete first;
      delete second;
      throw AssertException(what);
    }
  delete first;
  delete second;
  return 0;
}

int            VirtualCPU::assert_get(IOperand *elem) {
  eOperandType accuracy = (elem->getPrecision() > _mutantStack->top()->getPrecision() ? elem->getType() : _mutantStack->top()->getType());
  IOperand *first = createOperand(accuracy, _mutantStack->top()->toString());
  IOperand *second = createOperand(accuracy, elem->toString());
  delete elem;
  std::stringstream s1, s2;
  double d1, d2;
  s1 << first->toString();
  s1 >> d1;
  s2 << second->toString();
  s2 >> d2;
  if (d1 <= d2)
    {
      std::string what = std::string("Comparaison GET between (") + first->toString() + ") and (" + second->toString() + ")";
      delete first;
      delete second;
      throw AssertException(what);
    }
  delete first;
  delete second;
  return 0;
}

int            VirtualCPU::assert_let(IOperand *elem) {
  eOperandType accuracy = (elem->getPrecision() > _mutantStack->top()->getPrecision() ? elem->getType() : _mutantStack->top()->getType());
  IOperand *first = createOperand(accuracy, _mutantStack->top()->toString());
  IOperand *second = createOperand(accuracy, elem->toString());
  delete elem;
  std::stringstream s1, s2;
  double d1, d2;
  s1 << first->toString();
  s1 >> d1;
  s2 << second->toString();
  s2 >> d2;
  if (d1 >= d2)
    {
      std::string what = std::string("Comparaison LET between (") + first->toString() + ") and (" + second->toString() + ")";
      delete first;
      delete second;
      throw AssertException(what);
    }
  delete first;
  delete second;
  return 0;
}

int		VirtualCPU::pop(__attribute__((unused)) IOperand *) {
  pop();
  return 0;
}

IOperand	*VirtualCPU::top() {
  if (_mutantStack->empty())
    throw PopException("Not enough element on the stack");
  return _mutantStack->top();
}

int		VirtualCPU::pop() {
  if (_mutantStack->empty())
    throw PopException("Not enough element on the stack to pop");
  _mutantStack->pop();
  return 0;
}

int            VirtualCPU::dump(__attribute__((unused)) IOperand *) {
  if (_mutantStack->empty())
    return 0;
  MutantStack<IOperand *>::iterator it = _mutantStack->begin();
  MutantStack<IOperand *>::iterator itlast = _mutantStack->last();

  while (itlast != it) {
#ifdef DUMP_WITH_PRECISION
    std::cout << (*itlast)->toString() << " (" << (*it)->getPrecision() << ")" << std::endl;
#else
    std::cout << (*itlast)->toString() << std::endl;
#endif
    --itlast;
  }
  if (itlast == it)
    {
#ifdef DUMP_WITH_PRECISION
      std::cout << (*itlast)->toString() << " (" << (*it)->getPrecision() << ")" << std::endl;
#else
      std::cout << (*itlast)->toString() << std::endl;
#endif
    }
  return 0;
}

int            VirtualCPU::add(__attribute__((unused)) IOperand *) {
  IOperand *second = top();
  pop();
  IOperand *first = top();
  pop();
  IOperand *result;
  try {
    result = *first + *second;
    _mutantStack->push(result);
  }
  catch  (const VMException &e) {
    delete first;
    delete second;
    throw;
  }
  delete first;
  delete second;
  return 0;
}

int            VirtualCPU::sub(__attribute__((unused)) IOperand *) {
  IOperand *second = top();
  pop();
  IOperand *first = top();
  pop();
  IOperand *result;
  try {
    result = *first - *second;
    _mutantStack->push(result);
  }
  catch  (const VMException &e) {
    delete first;
    delete second;
    throw;
  }
  delete first;
  delete second;
  return 0;
}

int            VirtualCPU::mul(__attribute__((unused)) IOperand *) {
  IOperand *second = top();
  pop();
  IOperand *first = top();
  pop();
  IOperand *result;
  try {
    result = *first * *second;
    _mutantStack->push(result);
  }
  catch  (const VMException &e) {
    delete first;
    delete second;
    throw;
  }
  delete first;
  delete second;
  return 0;
}

int            VirtualCPU::div(__attribute__((unused)) IOperand *) {
  IOperand *second = top();
  pop();
  IOperand *first = top();
  pop();
  IOperand *result;
  try {
    result = *first / *second;
    _mutantStack->push(result);
  }
  catch  (const VMException &e) {
    delete first;
    delete second;
    throw;
  }
  delete first;
  delete second;
  return 0;
}

int            VirtualCPU::mod(__attribute__((unused)) IOperand *) {
  IOperand *second = top();
  pop();
  IOperand *first = top();
  pop();
  IOperand *result;
  try {
    result = *first % *second;
    _mutantStack->push(result);
  }
  catch  (const VMException &e) {
    delete first;
    delete second;
    throw;
  }
  delete first;
  delete second;
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

# include <limits>

IOperand *	VirtualCPU::createOperand(eOperandType type, const std::string & value){
  return (this->*_ptrToOperand[type])(value);
}

IOperand *	VirtualCPU::createInt8(const std::string & value){
  if (value[0] != '-' && value > toString((long double)std::numeric_limits<char>::max()))
    throw SyntaxException(std::string("Overflow of ") + value + " for maxium at " + toString((long double)std::numeric_limits<char>::max()));
  if (value[0] == '-' && value > toString((long double)std::numeric_limits<char>::min()))
    throw SyntaxException(std::string("Overflow of ") + value + " for minimum at " + toString((long double)std::numeric_limits<char>::min()));
  return new Operand<char>(value, Int8);
}

IOperand *	VirtualCPU::createInt16(const std::string & value) {
  if (value[0] != '-' && value > toString((long double)std::numeric_limits<short>::max()))
    throw SyntaxException(std::string("Overflow of ") + value + " for maxium at " + toString((long double)std::numeric_limits<short>::max()));
  if (value[0] == '-' && value > toString((long double)std::numeric_limits<short>::min()))
    throw SyntaxException(std::string("Overflow of ") + value + " for minimum at " + toString((long double)std::numeric_limits<short>::min()));
  return new Operand<short>(value, Int16);
}

IOperand *	VirtualCPU::createInt32(const std::string & value) {
  if (value[0] != '-' && value > toString((long double)std::numeric_limits<int>::max()))
    throw SyntaxException(std::string("Overflow of ") + value + " for maxium at " + toString((long double)std::numeric_limits<int>::max()));
  if (value[0] == '-' && value > toString((long double)std::numeric_limits<int>::min()))
    throw SyntaxException(std::string("Overflow of ") + value + " for minimum at " + toString((long double)std::numeric_limits<int>::min()));
  return new Operand<int>(value, Int32);
}

IOperand *	VirtualCPU::createFloat(const std::string & value) {
  std::string max = toString((long double)std::numeric_limits<float>::max());
  // std::cout << "max = " << max << std::endl;
  // std::cout << "Number of digits > 0 : " << value.find_first_of(".") << std::endl;
  // std::cout << "Max number of digits > 0 : " << max.substr(max.find_first_of("e") + 2) << std::endl;
  if (value[0] != '-' && value.find_first_of(".") >= fromString<size_t>(max.substr(max.find_first_of("e") + 2)))
    throw SyntaxException(std::string("Overflow of ") + value + " for maxium at " + toString((long double)std::numeric_limits<float>::max()));
  if (value[0] == '-' && value.substr(1).find_first_of(".") >= fromString<size_t>(max.substr(max.find_first_of("e") + 2)))
    throw SyntaxException(std::string("Overflow of ") + value + " for maxium at " + toString((long double)std::numeric_limits<float>::min()));
  return new Operand<float>(value, Float);
}

IOperand *	VirtualCPU::createDouble(const std::string & value) {
  std::string max = toString((long double)std::numeric_limits<double>::max());
  if (value[0] != '-' && value.find_first_of(".") >= fromString<size_t>(max.substr(max.find_first_of("e") + 2)))
    throw SyntaxException(std::string("Overflow of ") + value + " for maxium at " + toString((long double)std::numeric_limits<double>::max()));
  if (value[0] == '-' && value.substr(1).find_first_of(".") >= fromString<size_t>(max.substr(max.find_first_of("e") + 2)))
    throw SyntaxException(std::string("Overflow of ") + value + " for maxium at " + toString((long double)std::numeric_limits<double>::min()));
  return new Operand<double>(value, Double);
}
