#include "Exceptions.hpp"

VMException::~VMException() throw() {}
VMException::VMException(std::string str)
{
  _str = std::string("VMException : ") + str;
}

const char *VMException::what() const throw()
{
  return _str.c_str();
}

IOException::~IOException() throw() {}
IOException::IOException(std::string str) : VMException(str)
{
  _str = std::string("IOException : ") + str;
}

ParseException::~ParseException() throw() {}
ParseException::ParseException(std::string str) : VMException(str)
{
  _str = std::string("ParseException : ") + str;
}

PopException::~PopException() throw() {}
PopException::PopException(std::string str) : VMException(str)
{
  _str = std::string("PopException : ") + str;
}

MathException::~MathException() throw() {}
MathException::MathException(std::string str) : VMException(str)
{
  _str = std::string("MathException : ") + str;
}

DecimalException::~DecimalException() throw() {}
DecimalException::DecimalException(std::string str) : MathException(str)
{
  _str = std::string("DecimalException : ") + str;
}

DivideByZeroException::~DivideByZeroException() throw() {}
DivideByZeroException::DivideByZeroException(std::string str) : MathException(str)
{
  _str = std::string("DivideByZeroException : ") + str;
}

OverflowException::~OverflowException() throw() {}
OverflowException::OverflowException(std::string str) : MathException(str)
{
  _str = std::string("OverflowException : ") + str;
}