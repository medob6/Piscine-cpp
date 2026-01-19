/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:06:52 by mbousset          #+#    #+#             */
/*   Updated: 2025/12/04 16:05:00 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void printInt(const int &x)
{
  std::cout << x << " ";
}

void increment(int &x)
{
  ++x;
}

void printString(const std::string &s)
{
  std::cout << "[" << s << "] ";
}

void uppercase(std::string &s)
{
  for (size_t i = 0; i < s.size(); ++i)
    s[i] = std::toupper(s[i]);
}

int main()
{
  std::cout << "===== Testing int array =====" << std::endl;
  int arr[] = {1, 2, 3, 4};
  const int carr[] = {10, 20, 30, 40};

  std::cout << "Original: ";
  iter(arr, 4, printInt);
  std::cout << std::endl;

  iter(arr, 4, increment);

  std::cout << "After increment: ";
  iter(arr, 4, printInt);
  std::cout << std::endl;

  std::cout << "Const array: ";
  iter(carr, 4, printInt);
  std::cout << std::endl;

  std::cout << "===== Testing string array =====" << std::endl;
  std::string words[] = {"hello", "world", "cpp"};

  std::cout << "Original: ";
  iter(words, 3, printString);
  std::cout << std::endl;

  iter(words, 3, uppercase);

  std::cout << "After uppercase: ";
  iter(words, 3, printString);
  std::cout << std::endl;

  return 0;
}
