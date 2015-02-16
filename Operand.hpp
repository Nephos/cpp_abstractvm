#ifndef OPERAND_H_
# define OPERAND_H_

# include <iostream>
# include <sstream>
# include "IOperand.hpp"

template <typename T>
class Operand : public IOperand
{
public:
  enum eOperandType {Int8, Int16, Int32, Float, Double};

  Operand(const T &rhs) {
    _v = rhs;
  }

  virtual ~Operand() {}

  virtual std::string const & toString() const {
    std::stringstream s(_v);
    return s.str();
  }

  virtual int getPrecision() const {
    return sizeof(_v);
  }

  virtual eOperandType getType() const {
    // todo
  }

  virtual T * operator+(const T &rhs) const {
    return new T(_v + rhs._v);
  }

  virtual T * operator-(const T &rhs) const {
    return new T(_v - rhs._v);
  }

  virtual T * operator*(const T &rhs) const {
    return new T(_v * rhs._v);
  }

  virtual T * operator/(const T &rhs) const {
    //raise on rhs._v == 0
    return new T(_v / rhs._v);
  }

  virtual T * operator%(const T &rhs) const {
    //raise on rhs._v == 0
    return new T(_v % rhs._v);
  }

private:
  Operand(const Operand &);
  Operand &operator=(const Operand &);

protected:
  T	_v;

};

#endif /* !OPERAND_H_ */
