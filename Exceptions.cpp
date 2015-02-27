#include "std_improve.hpp"
#include "Exceptions.hpp"

VMException::~VMException() throw() {}
VMException::VMException(std::string str)
{
  _str = std::string("VMException : ") + str;
}

const char *VMException::what() const throw()
{
  return (std::string("(<") + _file + ">:" + toString(_line) + ") " + _str).c_str();
}

void	VMException::setLine(size_t line) {
  _line = line;
}

void	VMException::setFile(std::string file) {
  _file = file;
}

ExitException::~ExitException() throw() {}
ExitException::ExitException(std::string str) : VMException(str)
{
  _str = std::string("ExitException : ") + str;
}

AssertException::~AssertException() throw() {}
AssertException::AssertException(std::string str) : VMException(str)
{
  _str = std::string("AssertException : ") + str;
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

NoExitException::~NoExitException() throw() {}
NoExitException::NoExitException(std::string str) : ParseException(str)
{
  _str = std::string("NoExitException : ") + str;
}

SyntaxException::~SyntaxException() throw() {}
SyntaxException::SyntaxException(std::string str) : ParseException(str)
{
  _str = std::string("SyntaxException : ") + str;
}

MalformedNumericException::~MalformedNumericException() throw() {}
MalformedNumericException::MalformedNumericException(std::string str) : SyntaxException(str)
{
  _str = std::string("MalformedNumericException : ") + str;
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

UnderflowException::~UnderflowException() throw() {}
UnderflowException::UnderflowException(std::string str) : MathException(str)
{
  _str = std::string("UnderflowException : ") + str;
}
