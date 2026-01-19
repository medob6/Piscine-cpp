/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DoubleLiteral.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 09:08:58 by mbousset          #+#    #+#             */
/*   Updated: 2025/12/03 09:10:07 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DoubleLiteral.hpp"

DoubleLiteral::DoubleLiteral() : _value(0.0) {}

DoubleLiteral::DoubleLiteral(const DoubleLiteral &other) : Literal(other), _value(other._value) {}

DoubleLiteral::DoubleLiteral(const std::string &s)
{
  if (s == "nan")
    _value = std::numeric_limits<double>::quiet_NaN();
  else if (s == "+inf" || s == "inf")
    _value = std::numeric_limits<double>::infinity();
  else if (s == "-inf")
    _value = -std::numeric_limits<double>::infinity();
  else
    _value = strtod(s.c_str(), NULL);
}

DoubleLiteral &DoubleLiteral::operator=(const DoubleLiteral &other)
{
  if (this != &other)
  {
    Literal::operator=(other);
    _value = other._value;
  }
  return *this;
}
DoubleLiteral::~DoubleLiteral() {}

void DoubleLiteral::print() const
{
  printChar(_value);
  printInt(_value);
  printFloat(_value);
  printDouble(_value);
}
