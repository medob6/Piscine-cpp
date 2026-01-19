/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 17:13:44 by mbousset          #+#    #+#             */
/*   Updated: 2025/12/04 18:05:09 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
private:
  T *List;
  unsigned int size_;

public:
  class UnvalidIndex : std::exception
  {
  public:
    const char *what() const throw()
    {
      return " index is out of bounds";
    }
  };

  Array();
  Array(const Array &other);
  Array(unsigned int n);
  Array &operator=(const Array &other);
  T &operator[](size_t index);
  ~Array();

  size_t size() const;
};

#include "Array.tpp"

#endif