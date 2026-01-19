/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 08:43:32 by mbousset          #+#    #+#             */
/*   Updated: 2025/12/08 13:15:33 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iterator>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T &container, int toFind)
{
  typename T::iterator it = std::find(container.begin(), container.end(), toFind);
  if (it == container.end())
    throw std::runtime_error("Value not found in container");

  return (it);
}

template <typename T>
typename T::const_iterator easyfind(const T &container, int toFind)
{
  typename T::const_iterator it = std::find(container.begin(), container.end(), toFind);
  if (it == container.end())
    throw std::runtime_error("Value not found in container");

  return (it);
}

// this is a bonus added by me , soo i didn't handel the case of const arr of ints for example it's just for
// the sake of testing
template <typename T, size_t N>
T *easyfind(T (&arr)[N], const T &value)
{
  T *it = std::find(arr, arr + N, value);

  if (it == arr + N)
    throw std::runtime_error("Value not found in raw array");

  return it;
}

#endif