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

protected:
  std::string _str;
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

class SyntaxException : public ParseException
{
public:
  SyntaxException(std::string str);
  virtual ~SyntaxException() throw();
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

#endif /* !EXCEPTIONS_H_ */
