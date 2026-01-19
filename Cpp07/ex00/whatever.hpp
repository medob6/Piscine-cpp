/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 14:48:32 by mbousset          #+#    #+#             */
/*   Updated: 2025/12/04 15:05:30 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename T>
static void swap(T &a, T &b)
{
  T temp = a;
  a = b;
  b = temp;
}

template <typename T>
static T const &min(T const &a, T const &b)
{
  return (a < b ? a : b);
}

template <typename T>
static T const &max(T const &a, T const &b)
{
  return (a > b ? a : b);
}

#endif