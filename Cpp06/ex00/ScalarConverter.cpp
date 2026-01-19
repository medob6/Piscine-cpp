/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 08:49:27 by mbousset          #+#    #+#             */
/*   Updated: 2025/12/03 17:37:45 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "CharLiteral.hpp"
#include "IntLiteral.hpp"
#include "FloatLiteral.hpp"
#include "DoubleLiteral.hpp"
#include "Literal.hpp"

enum LiteralType
{
  CHAR,
  INT,
  FLOAT,
  DOUBLE,
  INVALID
};

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &other) { (void)other; }
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
  (void)other;
  return *this;
}
ScalarConverter::~ScalarConverter() {}

bool hasFraction(double x)
{
  double intPart;
  return std::modf(x, &intPart) != 0.0;
}

bool isDouble(const std::string &s)
{
  if (s == "nan" || s == "+inf" || s == "-inf" || s == "inf")
    return true;

  if (s.empty())
    return false;

  size_t i = (s[0] == '+' || s[0] == '-');

  size_t dot = s.find('.');
  if (dot != s.rfind('.'))
    return false;

  if (s.find_first_not_of("0123456789.", i) != std::string::npos)
    return false;

  return true;
}

bool isFloat(const std::string &s)
{
  if (s == "nanf" || s == "+inff" || s == "-inff" || s == "inff")
    return true;

  if (s[s.size() - 1] != 'f')
    return false;

  std::string core = s.substr(0, s.size() - 1);
  if (core.empty())
    return false;

  size_t i = (core[0] == '+' || core[0] == '-');

  if (core.find_first_not_of("0123456789.", i) != std::string::npos)
    return false;

  size_t dot = core.find('.');
  if (dot != core.rfind('.'))
    return false;

  return true;
}

bool isInt(const std::string &s)
{
  if (s.empty())
    return false;

  size_t i = (s[0] == '+' || s[0] == '-');

  return (i < s.size()) &&
         s.find_first_not_of("0123456789", i) == std::string::npos;
}

LiteralType get_type(const std::string &literal)
{
  if (literal.length() == 1 && !isdigit(literal[0]))
    return CHAR;
  else if (isFloat(literal))
    return FLOAT;
  else if (isDouble(literal))
    return DOUBLE;
  else if (isInt(literal))
    return INT;
  return INVALID;
}

void ScalarConverter::convert(const std::string &literal)
{
  Literal *obj = NULL;

  switch (get_type(literal))
  {
  case DOUBLE:
    obj = new DoubleLiteral(literal);
    break;
  case FLOAT:
    obj = new FloatLiteral(literal);
    break;
  case INT:
    obj = new IntLiteral(literal);
    break;
  case CHAR:
    obj = new CharLiteral(literal[0]);
    break;
  default:
    std::cout << "char: impossible\nint: impossible\n"
                 "float: impossible\ndouble: impossible\n\n";
    return;
  }

  obj->print();
  delete obj;
}
