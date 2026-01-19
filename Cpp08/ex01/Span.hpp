/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 09:52:36 by mbousset          #+#    #+#             */
/*   Updated: 2025/12/08 13:26:09 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <climits>
#include <vector>

class Span
{
private:
  std::vector<int> numbers;
  const unsigned int capacity;

public:
  Span();
  Span(unsigned int N);
  Span(const Span &other);
  Span &operator=(const Span &other);
  ~Span();

  class SpanFullException : public std::exception
  {
    const char *what() const throw()
    {
      return "Span is full";
    }
  };
  class NotEnoughNumbersException : public std::exception
  {
    const char *what() const throw()
    {
      return "Not enough numbers to calculate a span";
    }
  };

  void addNumber(int number);
  unsigned int shortestSpan();
  unsigned int longestSpan();
  
  //template func/classes can be defined in the header file 
  template <typename It>
  void addRange(It begin, It end)
  {
    if (std::distance(begin, end) + numbers.size() > capacity)
      throw SpanFullException();

    numbers.insert(numbers.end(), begin, end);
  }
};

#endif