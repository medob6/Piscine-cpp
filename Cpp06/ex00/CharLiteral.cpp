/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CharLiteral.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 09:04:44 by mbousset          #+#    #+#             */
/*   Updated: 2025/12/03 09:05:15 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CharLiteral.hpp"

CharLiteral::CharLiteral(char value) : _value(value) {}
CharLiteral::CharLiteral(const CharLiteral &other) : Literal(other), _value(other._value) {}
CharLiteral &CharLiteral::operator=(const CharLiteral &other)
{
  if (this != &other)
  {
    Literal::operator=(other);
    _value = other._value;
  }
  return *this;
}

CharLiteral::~CharLiteral() {}

void CharLiteral::print() const
{
  double v = static_cast<double>(_value);
  printChar(v);
  printInt(v);
  printFloat(v);
  printDouble(v);
}
