/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:06:55 by mbousset          #+#    #+#             */
/*   Updated: 2025/12/05 08:31:22 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>
#include <iostream>

// case 1

// template <typename T, typename T2>
// void iter(T *arr, std::size_t length, void (*func)(T2))
// {
//   for (std::size_t i = 0; i < length; ++i)
//     func(arr[i]);
// }

// case 2

// template <typename T>
// void iter(T *arr, std::size_t length, void (*func)(T &))
// {
//   for (std::size_t i = 0; i < length; ++i)
//     func(arr[i]);
// }

// template <typename T>
// void iter(const T *arr, std::size_t length, void (*func)(const T &))
// {
//   for (std::size_t i = 0; i < length; ++i)
//     func(arr[i]);
// }

// case 3

template <typename T, typename N, typename F>
void iter(T arr, N length, F func)
{
  for (N i = 0; i < length; ++i)
    func(arr[i]);
}

#endif
