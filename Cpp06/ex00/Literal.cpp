/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Literal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 08:51:53 by mbousset          #+#    #+#             */
/*   Updated: 2025/12/03 17:53:32 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Literal.hpp"

Literal::Literal() {}
Literal::Literal(const Literal &other) { (void)other; }
Literal &Literal::operator=(const Literal &other)
{
  (void)other;
  return *this;
}
Literal::~Literal() {}

void Literal::printChar(double v) const
{
  std::cout << "char: ";

  if (std::isnan(v) || v < 0 || v > 127)
    std::cout << "impossible\n";
  else if (isprint(static_cast<char>(v)))
    std::cout << "'" << static_cast<char>(v) << "'\n";
  else
    std::cout << "Non displayable\n";
}

void Literal::printInt(double v) const
{
  std::cout << "int: ";

  if (std::isnan(v) || v > INT_MAX || v < INT_MIN)
    std::cout << "impossible\n";
  else
    std::cout << static_cast<int>(v) << "\n";
}

void Literal::printFloat(double v) const
{
  std::cout << "float: ";
  float f = static_cast<float>(v);
  if (std::isnan(f))
  {
    std::cout << "nanf\n";
    return;
  }
  if (std::isinf(f))
  {
    std::cout << (f > 0 ? "+inff\n" : "-inff\n");
    return;
  }

  std::ios::fmtflags oldFlags = std::cout.flags();
  std::streamsize oldPrecision = std::cout.precision();

  if (f == static_cast<long long>(f))
    std::cout << std::fixed << std::setprecision(1) << f << "f\n";
  else
    std::cout << f << "f\n";

  std::cout.flags(oldFlags);
  std::cout.precision(oldPrecision);
}

void Literal::printDouble(double v) const
{
  std::cout << "double: ";

  if (std::isnan(v))
  {
    std::cout << "nan\n";
    return;
  }
  if (std::isinf(v))
  {
    std::cout << (v > 0 ? "+inf\n" : "-inf\n");
    return;
  }

  std::ios::fmtflags oldFlags = std::cout.flags();
  std::streamsize oldPrecision = std::cout.precision();

  if (v == static_cast<long long>(v))
    std::cout << std::fixed << std::setprecision(1) << v << "\n";
  else
    std::cout << v << "\n";

  std::cout.flags(oldFlags);
  std::cout.precision(oldPrecision);
}
