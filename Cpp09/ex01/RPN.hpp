/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 17:18:21 by mbousset          #+#    #+#             */
/*   Updated: 2025/12/18 23:34:24 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <cstring>
#include <cerrno>

// RPN = Reverse Polish Notation
class RPN
{
public:
  // canonic form
  RPN();
  RPN(const RPN &other);
  RPN(const std::string &token, int argc);
  RPN &operator=(const RPN &other);
  ~RPN();
  // exception class
  class Error : public std::runtime_error
  {
  public:
    explicit Error(const std::string &msg) : std::runtime_error(msg) {}
  };
  // RPN methods
  void pushNumber(char number);
  void performOperation(char op);
  void skip_space(size_t *i);
  // this three will be used inside this one below
  void processToken();
  double getResult() const;

private:
  std::stack<double> _stack;
  const std::string token;
};

#endif