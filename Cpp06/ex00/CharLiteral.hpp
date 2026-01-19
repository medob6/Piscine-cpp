/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CharLiteral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 08:38:44 by mbousset          #+#    #+#             */
/*   Updated: 2025/12/03 09:06:58 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARLITERAL_HPP
#define CHARLITERAL_HPP

#include "Literal.hpp"

class CharLiteral : public Literal
{
private:
  char _value;

public:
  CharLiteral(char value);
  CharLiteral(const CharLiteral &other);
  CharLiteral &operator=(const CharLiteral &other);
  ~CharLiteral();

  void print() const;
};

#endif