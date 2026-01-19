/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 17:20:14 by mbousset          #+#    #+#             */
/*   Updated: 2025/12/04 17:59:50 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array()
{
  size_ = 0;
  List = NULL;
}

template <typename T>
Array<T>::Array(unsigned int n) : size_(n)
{
  List = new T[n];
}

template <typename T>
Array<T>::Array(const Array<T> &other) : size_(other.size_)
{
  List = new T[size_];
  for (size_t i = 0; i < size_; ++i)
    List[i] = other.List[i];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &other)
{
  if (this != &other)
  {
    delete[] List;
    size_ = other.size_;
    List = new T[size_];
    for (size_t i = 0; i < size_; i++)
      List[i] = other.List[i];
  }
  return *this;
}

template <typename T>
Array<T>::~Array()
{
  delete[] List;
}

template <typename T>
T &Array<T>::operator[](size_t index)
{
  if (index >= size_)
    throw UnvalidIndex();
  return List[index];
}

template <typename T>
size_t Array<T>::size() const
{
  return size_;
}