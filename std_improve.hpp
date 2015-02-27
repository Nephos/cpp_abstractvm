#ifndef STD_IMPROVE_H_
# define STD_IMPROVE_H_

# include <string>
# include <sstream>

template <typename T>
T	fromString(std::string str)
{
  std::stringstream s;
  T v;
  s << str;
  s >> v;
  return v;
}

template <typename T>
std::string	toString(T v)
{
  std::stringstream s;
  std::string str;
  s << v;
  s >> str;
  return str;
}

#endif /* !STD_IMPROVE_H_ */
