/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DoubleLiteral.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 08:38:48 by mbousset          #+#    #+#             */
/*   Updated: 2025/12/03 09:10:01 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOUBLE_HPP
#define DOUBLE_HPP

#include "Literal.hpp"

class DoubleLiteral : public Literal
{
  double _value;

public:
  DoubleLiteral();
  DoubleLiteral(const std::string &s);
  DoubleLiteral(const DoubleLiteral &other);
  DoubleLiteral &operator=(const DoubleLiteral &other);
  ~DoubleLiteral();

    void print() const;
};

#endif