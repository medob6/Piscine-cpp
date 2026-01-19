/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Literal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 08:45:44 by mbousset          #+#    #+#             */
/*   Updated: 2025/12/03 09:03:27 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALITERAL_HPP
#define ALITERAL_HPP
#include "ScalarConverter.hpp"

class Literal
{
public:
  Literal();
  Literal(const Literal &other);
  Literal &operator=(const Literal &other);
  virtual ~Literal();
  virtual void print() const = 0;

protected:
  void printChar(double v) const;
  void printInt(double v) const;
  void printFloat(double v) const;
  void printDouble(double v) const;
};

#endif