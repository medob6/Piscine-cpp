/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FloatLiteral.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 08:38:51 by mbousset          #+#    #+#             */
/*   Updated: 2025/12/03 09:11:38 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOATLITERAL_HPP
#define FLOATLITERAL_HPP

#include "Literal.hpp"

class FloatLiteral : public Literal
{
  float _value;

public:
  FloatLiteral();
  FloatLiteral(const std::string &s);
  FloatLiteral(const FloatLiteral &other);
  FloatLiteral &operator=(const FloatLiteral &other);
  ~FloatLiteral();

  void print() const;
};

#endif