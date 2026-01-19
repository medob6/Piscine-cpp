/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 10:11:50 by mbousset          #+#    #+#             */
/*   Updated: 2025/12/05 15:16:18 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : capacity(0) {}

Span::Span(unsigned int N) : capacity(N) {}

Span::Span(const Span &other)
    : numbers(other.numbers), capacity(other.capacity)
{
}

Span &Span::operator=(const Span &other)
{
  if (this != &other)
  {
    if (other.numbers.size() > this->capacity)
      throw SpanFullException();

    this->numbers = other.numbers;
  }
  return *this;
}

Span::~Span() {}

void Span::addNumber(int number)
{
  if (numbers.size() >= capacity)
    throw SpanFullException();
  numbers.push_back(number);
}

unsigned int Span::shortestSpan()
{
  if (numbers.size() < 2)
    throw NotEnoughNumbersException();

  std::vector<int> sortedNumbers = numbers;
  std::sort(sortedNumbers.begin(), sortedNumbers.end());

  unsigned int minSpan = UINT_MAX;
  for (size_t i = 1; i < sortedNumbers.size(); ++i)
  {
    unsigned int span = sortedNumbers[i] - sortedNumbers[i - 1];
    if (span < minSpan)
      minSpan = span;
  }
  return minSpan;
}

unsigned int Span::longestSpan()
{
  if (numbers.size() < 2)
    throw NotEnoughNumbersException();

  int minValue = *std::min_element(numbers.begin(), numbers.end());
  int maxValue = *std::max_element(numbers.begin(), numbers.end());

  return maxValue - minValue;
}
