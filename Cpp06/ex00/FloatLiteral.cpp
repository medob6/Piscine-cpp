/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FloatLiteral.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 09:11:48 by mbousset          #+#    #+#             */
/*   Updated: 2025/12/03 09:18:15 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FloatLiteral.hpp"

FloatLiteral::FloatLiteral() : _value(0.0f) {}
FloatLiteral::FloatLiteral(const FloatLiteral &other) : Literal(other), _value(other._value) {}
FloatLiteral &FloatLiteral::operator=(const FloatLiteral &other)
{
  if (this != &other)
  {
    Literal::operator=(other);
    _value = other._value;
  }
  return *this;
}
FloatLiteral::~FloatLiteral() {}

FloatLiteral::FloatLiteral(const std::string &s)
{
  if (s == "nanf")
    _value = std::numeric_limits<float>::quiet_NaN();
  else if (s == "+inff")
    _value = std::numeric_limits<float>::infinity();
  else if (s == "-inff")
    _value = -std::numeric_limits<float>::infinity();
  else
    _value = strtof(s.c_str(), NULL);
}

void FloatLiteral::print() const
{
  printChar(_value);
  printInt(_value);
  printFloat(_value);
  printDouble(_value);
}
