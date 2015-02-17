#ifndef EXCEPTIONS_H_
# define EXCEPTIONS_H_

# include <exception>

class VMException : public std::exception
{
public:
  virtual ~VMException() throw() { }
  virtual const char *what() const throw();
};

class ParseException : public VMException
{
public:
  virtual ~ParseException() throw() { }
};

class PopException : public VMException
{
public:
  virtual ~PopException() throw() { }
};

class MathException : public VMException
{
public:
  virtual ~MathException() throw() { }
};

class DecimalException : public MathException
{
public:
  virtual ~DecimalException() throw() { }
};

class DivideByZeroException : public MathException
{
public:
  virtual ~DivideByZeroException() throw() { }
};

class OverflowException : public MathException
{
public:
  virtual ~OverflowException() throw() { }
};

#endif /* !EXCEPTIONS_H_ */
