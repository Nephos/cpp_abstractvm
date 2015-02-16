#ifndef IOPERAND_H_
# define IOPERAND_H_

# include <string>

enum eOperandType {Int8 = 1, Int16 = 2, Int32 = 4, Float = 5, Double = 8};

class IOperand
{
public:
  virtual std::string const & toString() const = 0; // Renvoie une string reprensentant l’instance
  virtual int getPrecision() const = 0; // Renvoie la precision du type de l’instance
  virtual eOperandType getType() const = 0; // Renvoie le type de l’instance. Voir plus bas

  virtual IOperand * operator+(const IOperand &rhs) const = 0;
  virtual IOperand * operator-(const IOperand &rhs) const = 0;
  virtual IOperand * operator*(const IOperand &rhs) const = 0;
  virtual IOperand * operator/(const IOperand &rhs) const = 0;
  virtual IOperand * operator%(const IOperand &rhs) const = 0;

  virtual ~IOperand() {}
};


#endif /* !IOPERAND_H_ */
