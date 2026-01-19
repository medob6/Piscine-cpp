/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IntLiteral.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 08:38:53 by mbousset          #+#    #+#             */
/*   Updated: 2025/12/03 09:16:42 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTLITERAL_HPP
#define INTLITERAL_HPP
#include "Literal.hpp"

class IntLiteral : public Literal
{
private:
  int _value;

public:
  IntLiteral();
  IntLiteral(const IntLiteral &other);
  IntLiteral(const std::string &s);
  IntLiteral &operator=(const IntLiteral &other);
  ~IntLiteral();

  void print() const;
};

#endif