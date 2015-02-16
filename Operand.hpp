#ifndef OPERAND_H_
# define OPERAND_H_

# include <iostream>
# include <sstream>
# include "IOperand.hpp"

template <typename T>
class Operand : public IOperand
{
public:
  Operand(const T &value, const eOperandType type) : _value(value), _type(type) {
    std::stringstream s;
    s << value;
    _string = s.str();
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
    U v;
    s << op.toString();
    s >> v;
    return v;
  }

  virtual IOperand * operator+(const IOperand &rhs) const {
    if (rhs.getPrecision() > getPrecision())
      return (rhs + *this);
    return new Operand<T>(getValue<T>(*this) + getValue<T>(rhs), _type);
  }

  virtual IOperand * operator-(const IOperand &rhs) const {
  }

  virtual IOperand * operator*(const IOperand &rhs) const {
  }

  virtual IOperand * operator/(const IOperand &rhs) const {
    //raise on rhs._value == 0
  }

  virtual IOperand * operator%(const IOperand &rhs) const {
    //raise on rhs._value == 0
  }

private:
  Operand(const Operand &);
  Operand &operator=(const Operand &);

protected:
  T		_value;
  eOperandType	_type;
  std::string	_string;

};

#endif /* !OPERAND_H_ */
