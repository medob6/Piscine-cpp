/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 09:05:34 by mbousset          #+#    #+#             */
/*   Updated: 2025/12/03 18:32:13 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void sepratetor()
{
  std::cout << "\n--------------------------\n";
}

#define DOUBLE_MAX 1.7976931348623157e+308

int main()
{
  std::cout << "===== CHAR =====\n";
  ScalarConverter::convert("a");
  sepratetor();
  ScalarConverter::convert("Z");
  sepratetor();
  ScalarConverter::convert("!");
  sepratetor();

  std::cout << "===== INT =====\n";
  ScalarConverter::convert("42");
  sepratetor();

  ScalarConverter::convert("-42");
  sepratetor();

  ScalarConverter::convert("127"); // max ASCII
  sepratetor();

  ScalarConverter::convert("128"); // non-displayable
  sepratetor();

  ScalarConverter::convert("0");
  sepratetor();

  std::cout << "===== FLOAT =====\n";
  ScalarConverter::convert("42.0f");
  sepratetor();
  ScalarConverter::convert("42.42f");
  sepratetor();

  ScalarConverter::convert("-42.01f");
  sepratetor();

  ScalarConverter::convert("nanf");
  sepratetor();

  ScalarConverter::convert("+inff");
  sepratetor();

  ScalarConverter::convert("-inff");
  sepratetor();

  std::cout << "===== DOUBLE =====\n";
  ScalarConverter::convert("42.0");
  sepratetor();

  ScalarConverter::convert("42.42");
  sepratetor();

  ScalarConverter::convert("-42.0");
  sepratetor();

  ScalarConverter::convert("nan");
  sepratetor();

  ScalarConverter::convert("+inf");
  sepratetor();

  ScalarConverter::convert("-inf");
  sepratetor();

  std::cout << "===== INVALID =====\n";
  ScalarConverter::convert("hello");
  sepratetor();

  ScalarConverter::convert("42a");
  sepratetor();

  ScalarConverter::convert("f");
  sepratetor();

  ScalarConverter::convert("42..0");
  sepratetor();

  ScalarConverter::convert(".");
  sepratetor();

  std::cout << "===== OVERFLOW =====\n";
  ScalarConverter::convert("2147483648");
  sepratetor();
  ScalarConverter::convert("21474836555"); // INT_MIN - 1
  sepratetor();
  ScalarConverter::convert("-1e40");
  sepratetor();

  return 0;
}
