#ifndef EXCEPTIONS_H_
# define EXCEPTIONS_H_

# include <exception>
# include <string>

class VMException : public std::exception
{
public:
  VMException(std::string str);
  virtual ~VMException() throw();
  const char *what() const throw();
  void setLine(size_t line);
  void setFile(std::string file);

protected:
  std::string _str;
  size_t _line;
  std::string _file;
};

class ExitException : public VMException
{
public:
  ExitException(std::string str);
  virtual ~ExitException() throw();
};

class AssertException : public VMException
{
public:
  AssertException(std::string str);
  virtual ~AssertException() throw();
};

class IOException : public VMException
{
public:
  IOException(std::string str);
  virtual ~IOException() throw();
};

class ParseException : public VMException
{
public:
  ParseException(std::string str);
  virtual ~ParseException() throw();
};

class NoExitException : public ParseException
{
public:
  NoExitException(std::string str);
  virtual ~NoExitException() throw();
};

class SyntaxException : public ParseException
{
public:
  SyntaxException(std::string str);
  virtual ~SyntaxException() throw();
};

class MalformedNumericException : public SyntaxException
{
public:
  MalformedNumericException(std::string str);
  virtual ~MalformedNumericException() throw();
};

class PopException : public VMException
{
public:
  PopException(std::string str);
  virtual ~PopException() throw();
};

class MathException : public VMException
{
public:
  MathException(std::string str);
  virtual ~MathException() throw();
};

class DecimalException : public MathException
{
public:
  DecimalException(std::string str);
  virtual ~DecimalException() throw();
};

class DivideByZeroException : public MathException
{
public:
  DivideByZeroException(std::string str);
  virtual ~DivideByZeroException() throw();
};

class OverflowException : public MathException
{
public:
  OverflowException(std::string str);
  virtual ~OverflowException() throw();
};

class UnderflowException : public MathException
{
public:
  UnderflowException(std::string str);
  virtual ~UnderflowException() throw();
};

#endif /* !EXCEPTIONS_H_ */
