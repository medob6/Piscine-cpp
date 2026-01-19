/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 09:52:55 by mbousset          #+#    #+#             */
/*   Updated: 2025/12/05 15:28:22 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

int main()
{
  std::cout << "===== Basic Tests =====" << std::endl;
  try
  {
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl; // 2
    std::cout << "Longest span : " << sp.longestSpan() << std::endl;  // 14
  }
  catch (std::exception &e)
  {
    std::cout << "Exception: " << e.what() << std::endl;
  }

  std::cout << "\n===== Exception Tests =====" << std::endl;
  try
  {
    Span sp(2);
    sp.addNumber(10);
    sp.addNumber(20);
    sp.addNumber(30); // should throw
  }
  catch (std::exception &e)
  {
    std::cout << "Caught: " << e.what() << std::endl;
  }

  try
  {
    Span sp(1);
    sp.addNumber(5);
    std::cout << sp.shortestSpan(); // should throw
  }
  catch (std::exception &e)
  {
    std::cout << "Caught: " << e.what() << std::endl;
  }

  std::cout << "\n===== Range Insert Test =====" << std::endl;
  try
  {
    std::vector<int> v;
    for (int i = 0; i < 10; i++)
      v.push_back(i * 2);

    Span sp(10);
    sp.addRange(v.begin(), v.end());

    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span : " << sp.longestSpan() << std::endl;
  }
  catch (std::exception &e)
  {
    std::cout << "Caught: " << e.what() << std::endl;
  }

  std::cout << "\n===== 10,000 Numbers Test =====" << std::endl;
  try
  {
    const int N = 10000;
    std::vector<int> big(N);

    // Fill vector with values 0..9999
    for (int i = 0; i < N; i++)
      big[i] = i;

    Span sp(N);
    sp.addRange(big.begin(), big.end());

    std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl; // should be 1
    std::cout << "Longest Span : " << sp.longestSpan() << std::endl;  // should be 9999
  }
  catch (std::exception &e)
  {
    std::cout << "Caught: " << e.what() << std::endl;
  }

  return 0;
}
