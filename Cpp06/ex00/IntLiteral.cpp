/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IntLiteral.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 09:13:37 by mbousset          #+#    #+#             */
/*   Updated: 2025/12/03 09:18:24 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IntLiteral.hpp"

IntLiteral::IntLiteral() : _value(0) {}
IntLiteral::IntLiteral(const IntLiteral &other) : Literal(other), _value(other._value) {}
IntLiteral::IntLiteral(const std::string &s)
{
  _value = strtol(s.c_str(), NULL, 10);
}
IntLiteral &IntLiteral::operator=(const IntLiteral &other)
{
  if (this != &other)
  {
    Literal::operator=(other);
    _value = other._value;
  }
  return *this;
}
IntLiteral::~IntLiteral() {}

void IntLiteral::print() const
{
  double v = static_cast<double>(_value);
  printChar(v);
  printInt(v);
  printFloat(v);
  printDouble(v);
}