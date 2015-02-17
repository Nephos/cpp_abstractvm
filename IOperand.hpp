#ifndef IOPERAND_H_
# define IOPERAND_H_

# include <string>

# define INT8	char
# define INT16	short
# define INT32	int
# define FLOAT	float
# define DOUBLE	double
# define MAX	double
# define MAX2	long double

enum eOperandType {Int8, Int16, Int32, Float, Double};

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
