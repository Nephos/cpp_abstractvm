#ifndef OPERAND_H_
# define OPERAND_H_

# include <iostream>
# include <sstream>
# include "IOperand.hpp"

template <typename T>
class Operand : public IOperand
{
public:
  Operand(const T &value) : _v(value) {
    if (dynamic_cast<float *>(&value))
      _type = Float;
    else
      _type = sizeof(value);
  }

  virtual ~Operand() {}

  virtual std::string const & toString() const {
    std::stringstream s(_v);
    return s.str();
  }

  virtual int getPrecision() const {
    // return sizeof(_v);
    return static_cast<int>(getType());
  }

  virtual eOperandType getType() const {
    // todo
  }

  virtual IOperand * operator+(const T &rhs) const {
    return new Operand<T>(_v + rhs._v);
  }

  virtual IOperand * operator-(const T &rhs) const {
    return new Operand<T>(_v - rhs._v);
  }

  virtual IOperand * operator*(const T &rhs) const {
    return new Operand<T>(_v * rhs._v);
  }

  virtual IOperand * operator/(const T &rhs) const {
    //raise on rhs._v == 0
    return new Operand<T>(_v / rhs._v);
  }

  virtual IOperand * operator%(const T &rhs) const {
    //raise on rhs._v == 0
    return new Operand<T>(_v % rhs._v);
  }

private:
  Operand(const Operand &);
  Operand &operator=(const Operand &);

protected:
  T	_v;
  int	_type;

};

#endif /* !OPERAND_H_ */
