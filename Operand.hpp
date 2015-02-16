#ifndef OPERAND_H_
# define OPERAND_H_

# include <iostream>
# include <sstream>
# include "IOperand.hpp"

template <typename T>
class Operand : public IOperand
{
public:
  Operand(const std::string & string, const eOperandType type) : _type(type), _string(string) {
    std::stringstream s;
    s << string;
    s >> _value;
    std::cout << "1. The operand " << _string << std::endl;
  }

  Operand(const double & value, const eOperandType type) : _value(value), _type(type) {
    std::stringstream s;
    s << value;
    _string = s.str();
    std::cout << "T> " << value << std::endl;
    std::cout << "2. The operand " << _string << std::endl;
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

  static IOperand * const cloneWithType(const IOperand & op, const eOperandType type) {
    switch (type)
      {
      case Int8:
	return new Operand<char>(op.toString(), Int8);
	break;
      case Int16:
	return new Operand<short>(op.toString(), Int16);
	break;
      case Int32:
	return new Operand<int>(op.toString(), Int32);
	break;
      case Float:
	return new Operand<float>(op.toString(), Float);
	break;
      case Double:
	return new Operand<double>(op.toString(), Double);
	break;
      default:
	// throw error
	break;
      }
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
    //raise on rhs._value == 0
  }

  virtual IOperand * operator%(const IOperand &rhs) const {
    //raise on rhs._value == 0
  }

  Operand(const Operand & orig) : _value(orig._value), _type(orig._type), _string(orig._string) {
  }

protected:
  T		_value;
  eOperandType	_type;
  std::string	_string;

};

#endif /* !OPERAND_H_ */
