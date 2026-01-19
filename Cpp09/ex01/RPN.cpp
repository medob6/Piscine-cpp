/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 17:18:19 by mbousset          #+#    #+#             */
/*   Updated: 2025/12/28 18:13:19 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() : token("") {}

RPN::RPN(const std::string &token, int argc) : token(token)
{
  if (argc != 2)
    throw Error("Error: Invalid number of arguments.");
  if (token.empty())
    throw Error("Error: Empty expression.");
}
RPN::RPN(const RPN &other)
{
  this->_stack = other._stack;
}

RPN &RPN::operator=(const RPN &other)
{
  if (this != &other)
  {
    this->_stack = other._stack;
  }
  return *this;
}

RPN::~RPN() {}

void RPN::pushNumber(char number)
{
  if (!isdigit(number))
    throw RPN::Error("Error: Invalid token.");
  _stack.push(number - '0');
}

void RPN::performOperation(char op)
{
  if (_stack.size() < 2)
    throw Error("Error: Not enough operands in the stack");

  double b = _stack.top();
  _stack.pop();
  double a = _stack.top();
  _stack.pop();
  double result;

  switch (op)
  {
  case '+':
    result = a + b;
    break;
  case '-':
    result = a - b;
    break;
  case '*':
    result = a * b;
    break;
  case '/':
    if (b == 0)
      throw Error("Error: Division by zero");
    result = a / b;
    break;
  default:
    throw Error("Error: Unknown operator");
  }
  _stack.push(result);
}

void RPN::skip_space(size_t *i)
{
  if (!isspace(token[*i]))
  {
    std::ostringstream oss;
    oss << "Error: Invalid token in index: " << *i;
    throw RPN::Error(oss.str());
  }
  (*i)++;
}

void RPN::processToken()
{
  size_t i = 0;

  while (true)
  {
    if (strchr("+/*-", token[i]) == NULL)
      pushNumber(token[i]);
    else
      performOperation(token[i]);
    i++;
    if (i >= token.length())
      break;
    skip_space(&i);
  }
}

double RPN::getResult() const
{
  if (_stack.size() != 1)
    throw Error("Error: The user input has too many values.");
  return _stack.top();
}

// "9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"
