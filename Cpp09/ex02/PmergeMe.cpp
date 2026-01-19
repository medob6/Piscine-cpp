/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 10:02:37 by mbousset          #+#    #+#             */
/*   Updated: 2025/12/28 16:22:26 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int Integer::comparisonsCount = 0;

Integer::Integer() : value(0) { indexsList.clear(); }
Integer::Integer(const Integer &other) : value(other.value), indexsList(other.indexsList) {}
Integer &Integer::operator=(const Integer &other)
{
  if (this != &other)
  {
    value = other.value;
    indexsList = other.indexsList;
  }
  return *this;
}
Integer::~Integer() {}

Integer::Integer(int v) : value(v) {}

int Integer::getValue() const { return value; }

bool Integer::operator<(const Integer &other) const

{
  comparisonsCount++;
  return value < other.value;
}

bool Integer::operator!=(const Integer &other) const
{
  return (this->value != other.value);
}

bool Integer::operator==(const Integer &other) const
{
  return (this->value == other.value);
}

std::ostream &operator<<(std::ostream &os, const Integer &obj)
{
  os << obj.getValue();
  return os;
}

// Specializations for container names for display purposes dynamically
const char *container_name<std::vector<Integer> >::value = "vector";
const char *container_name<std::deque<Integer> >::value = "deque";

size_t sequenceNext(size_t k)
{
  size_t pow2 = 1;
  for (size_t i = 0; i <= k; ++i)
    pow2 *= 2;

  size_t sign = (k % 2 == 0) ? 1 : -1;
  return (pow2 + sign) / 3;
}

void binaryInsertion(size_t prevK, size_t K,
                     std::vector<Integer> &b_elements,
                     std::vector<Integer> &mainChain,
                     std::vector<size_t> &aPositions)
{
  for (size_t i = K; i > prevK; --i)
  {
    size_t idx = i - 1;

    std::vector<Integer>::iterator insert_pos =
        std::upper_bound(mainChain.begin(),
                         mainChain.begin() + aPositions[idx],
                         b_elements[idx]);

    size_t insertIndex = std::distance(mainChain.begin(), insert_pos);
    mainChain.insert(insert_pos, b_elements[idx]);

    for (size_t j = 0; j < aPositions.size(); ++j)
    {
      if (aPositions[j] >= insertIndex)
        ++aPositions[j];
    }
  }
}

std::vector<std::pair<Integer, Integer> > creatPairs(const std::vector<Integer> &l)
{
  std::vector<std::pair<Integer, Integer> > pairs;
  for (size_t i = 0; i + 1 < l.size(); i += 2)
  {
    Integer first = l[i];
    Integer second = l[i + 1];
    if (second < first)
      std::swap(first, second);
    pairs.push_back(std::make_pair(first, second));
    pairs.back().second.addIndex(i);
  }
  return pairs;
}

std::vector<Integer> pushLargerElements(const std::vector<std::pair<Integer, Integer> > &pairs)
{
  std::vector<Integer> largerElements;
  for (size_t i = 0; i < pairs.size(); i++)
  {
    largerElements.push_back(pairs[i].second);
  }
  return largerElements;
}

std::vector<std::pair<Integer, Integer> > rearrangePairs(
    const std::vector<Integer> &largerElements,
    const std::vector<std::pair<Integer, Integer> > &originalPairs,
    int lvl)
{
  std::vector<std::pair<Integer, Integer> > arrangePairs;
  for (size_t i = 0; i < largerElements.size(); i++)
  {
    size_t originalIndex = largerElements[i].getIndexAt(lvl - 1);
    arrangePairs.push_back(originalPairs[originalIndex / 2]);
  }
  return arrangePairs;
}

std::vector<Integer> creatMainChain(const std::vector<std::pair<Integer, Integer> > &sortedPairs)
{
  std::vector<Integer> mainChain;
  mainChain.push_back(sortedPairs[0].first);
  for (size_t i = 0; i < sortedPairs.size(); i++)
  {
    mainChain.push_back(sortedPairs[i].second);
  }
  return mainChain;
}

std::vector<Integer> storeB(const std::vector<std::pair<Integer, Integer> > &sortedPairs,
                            bool hasLeftover,
                            const Integer &leftOver)
{
  std::vector<Integer> b_elements;
  for (size_t i = 0; i < sortedPairs.size(); i++)
  {
    b_elements.push_back(sortedPairs[i].first);
  }
  if (hasLeftover)
    b_elements.push_back(leftOver);
  return b_elements;
}

void binaryInsertion(size_t prevK, size_t K,
                     std::deque<Integer> &b_elements,
                     std::deque<Integer> &mainChain,
                     std::vector<size_t> &aPositions)
{
  for (size_t i = K; i > prevK; --i)
  {
    size_t idx = i - 1;

    std::deque<Integer>::iterator insert_pos =
        std::upper_bound(mainChain.begin(),
                         mainChain.begin() + aPositions[idx],
                         b_elements[idx]);

    size_t insertIndex = std::distance(mainChain.begin(), insert_pos);
    mainChain.insert(insert_pos, b_elements[idx]);

    for (size_t j = 0; j < aPositions.size(); ++j)
    {
      if (aPositions[j] >= insertIndex)
        ++aPositions[j];
    }
  }
}

std::deque<std::pair<Integer, Integer> > creatPairs(const std::deque<Integer> &l)
{
  std::deque<std::pair<Integer, Integer> > pairs;
  for (size_t i = 0; i + 1 < l.size(); i += 2)
  {
    Integer first = l[i];
    Integer second = l[i + 1];
    if (second < first)
      std::swap(first, second);
    pairs.push_back(std::make_pair(first, second));
    pairs.back().second.addIndex(i);
  }
  return pairs;
}

std::deque<Integer> pushLargerElements(const std::deque<std::pair<Integer, Integer> > &pairs)
{
  std::deque<Integer> largerElements;
  for (size_t i = 0; i < pairs.size(); i++)
  {
    largerElements.push_back(pairs[i].second);
  }
  return largerElements;
}

std::deque<std::pair<Integer, Integer> > rearrangePairs(
    const std::deque<Integer> &largerElements,
    const std::deque<std::pair<Integer, Integer> > &originalPairs,
    int lvl)
{
  std::deque<std::pair<Integer, Integer> > arrangePairs;
  for (size_t i = 0; i < largerElements.size(); i++)
  {
    size_t originalIndex = largerElements[i].getIndexAt(lvl - 1);
    arrangePairs.push_back(originalPairs[originalIndex / 2]);
  }
  return arrangePairs;
}

std::deque<Integer> creatMainChain(const std::deque<std::pair<Integer, Integer> > &sortedPairs)
{
  std::deque<Integer> mainChain;
  mainChain.push_back(sortedPairs[0].first);
  for (size_t i = 0; i < sortedPairs.size(); i++)
  {
    mainChain.push_back(sortedPairs[i].second);
  }
  return mainChain;
}

std::deque<Integer> storeB(const std::deque<std::pair<Integer, Integer> > &sortedPairs,
                           bool hasLeftover,
                           const Integer &leftOver)
{
  std::deque<Integer> b_elements;
  for (size_t i = 0; i < sortedPairs.size(); i++)
  {
    b_elements.push_back(sortedPairs[i].first);
  }
  if (hasLeftover)
    b_elements.push_back(leftOver);
  return b_elements;
}
