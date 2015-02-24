#ifndef OPERAND_H_
# define OPERAND_H_

# include <iostream>
# include <sstream>
# include "IOperand.hpp"
# include "Exceptions.hpp"

template <typename T>
class Operand : public IOperand
{
public:
  Operand(const std::string & string, const eOperandType type) : _type(type), _string(string) {
    std::stringstream s;
    s << string;
    s >> _value;
    if ((_type == Double || _type == Float) && _string.find(".") == std::string::npos)
      _string += ".0";
  }

  Operand(const double & value, const eOperandType type) : _value(value), _type(type) {
    std::stringstream s;
    s << value;
    _string = s.str();
    if ((_type == Double || _type == Float) && _string.find(".") == std::string::npos)
      _string += ".0";
  }

  virtual ~Operand() {}

  virtual std::string const & toString() const {
    return _string;
  }

  virtual int getPrecision() const {
    return static_cast<int>(getType());
  }

  virtual eOperandType getType() const {
    return _type;
  }

  template <typename U>
  static const U getValue(const IOperand &op) {
    std::stringstream s;
    double v;
    s << op.toString();
    s >> v;
    return v;
  }

  static IOperand * cloneWithType(const IOperand & op, const eOperandType type) {
    switch (type)
      {
      case Int8:
	return new Operand<INT8>(op.toString(), Int8);
	break;
      case Int16:
	return new Operand<INT16>(op.toString(), Int16);
	break;
      case Int32:
	return new Operand<INT32>(op.toString(), Int32);
	break;
      case Float:
	return new Operand<FLOAT>(op.toString(), Float);
	break;
      case Double:
	return new Operand<DOUBLE>(op.toString(), Double);
	break;
      default:
	throw VMException("Unknow operand type");
	break;
      }
    return NULL;
  }

  virtual IOperand * operator+(const IOperand &rhs) const {
    if (rhs.getPrecision() > getPrecision())
      return (rhs + *this);
    return new Operand<T>(getValue<T>(*this) + getValue<T>(rhs), _type);
  }

  virtual IOperand * operator-(const IOperand &rhs) const {
    if (rhs.getPrecision() > getPrecision())
      {
	IOperand *tmp = cloneWithType(*this, rhs.getType());
	IOperand *result = *tmp - rhs;
	delete tmp;
	return result;
      }
    return new Operand<T>(getValue<T>(*this) - getValue<T>(rhs), _type);
  }

  virtual IOperand * operator*(const IOperand &rhs) const {
    if (rhs.getPrecision() > getPrecision())
      return (rhs * *this);
    return new Operand<T>(getValue<T>(*this) * getValue<T>(rhs), _type);
  }

  virtual IOperand * operator/(const IOperand &rhs) const {
    if (rhs.toString() == "0")
      throw DivideByZeroException("");
    if (rhs.getPrecision() > getPrecision())
      {
	IOperand *tmp = cloneWithType(*this, rhs.getType());
	IOperand *result = *tmp / rhs;
	delete tmp;
	return result;
      }
    return new Operand<T>(getValue<T>(*this) / getValue<T>(rhs), _type);
  }

  virtual IOperand * operator%(const IOperand &rhs) const {
    if (rhs.toString() == "0")
      throw DivideByZeroException("");
    if (rhs.getType() == Float || rhs.getType() == Double ||
	this->getType() == Float || this->getType() == Double)
      throw DecimalException("");
    if (rhs.getPrecision() > getPrecision())
      {
	IOperand *tmp = cloneWithType(*this, rhs.getType());
	IOperand *result = *tmp % rhs;
	delete tmp;
	return result;
      }
    return new Operand<T>(static_cast<int>(getValue<T>(*this)) % static_cast<int>(getValue<T>(rhs)), _type);
  }

  Operand(const Operand & orig) : _value(orig._value), _type(orig._type), _string(orig._string) {
  }

protected:
  T		_value;
  eOperandType	_type;
  std::string	_string;

};

#endif /* !OPERAND_H_ */
