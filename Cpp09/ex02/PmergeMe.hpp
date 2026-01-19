/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 08:52:59 by mbousset          #+#    #+#             */
/*   Updated: 2025/12/28 03:48:23 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <stdexcept>
#include <cstdlib>
#include <cerrno>
#include <climits>
#include <sstream>
#include <ctime>
#include <sys/time.h>
#include <typeinfo>
#include <algorithm>
#include <iomanip>

class Integer
{
private:
  int value;
  std::vector<size_t> indexsList;

public:
  // canonical form :
  static int comparisonsCount;
  Integer();
  Integer(const Integer &other);
  Integer &operator=(const Integer &other);
  ~Integer();
  Integer(int v);
  int getValue() const;

  bool operator<(const Integer &other) const;
  bool operator!=(const Integer &other) const;
  bool operator==(const Integer &other) const;

  // helpers for indexsList
  void addIndex(size_t idx) { indexsList.push_back(idx); }
  size_t getIndexAt(int lvl) const
  {
    if (lvl >= static_cast<int>(indexsList.size()))
      return 0;
    return indexsList[lvl];
  }
};

std::ostream &operator<<(std::ostream &os, const Integer &obj);

template <typename Container>
class PmergeMe
{
private:
  Container List;
  long sorting_time;

public:
  static std::string dataName;
  PmergeMe();
  explicit PmergeMe(int argc, char *input_list[]);
  PmergeMe(const PmergeMe &other);
  PmergeMe &operator=(const PmergeMe &other);
  ~PmergeMe();

  class Error : public std::runtime_error
  {
  public:
    explicit Error(const std::string &msg) : std::runtime_error(msg) {}
  };

  // main sorting function
  void sort();

  // Geters
  void display() const;
  double getSortingTime() const;
  const Container &getList() const;

  // utile
  static void sort_container(std::vector<Integer> &);
  static void sort_container(std::deque<Integer> &);
};

size_t sequenceNext(size_t k);

// i used a struct to avoid canonical form inforced by 42 norm
template <typename T>
struct container_name;

// Specializations for container names for display purposes dynamically
template <>
struct container_name<std::vector<Integer> >
{
  static const char *value;
};

template <>
struct container_name<std::deque<Integer> >
{
  static const char *value;
};

template <typename T>
PmergeMe<T>::PmergeMe() : List() {}

template <typename T>
std::string PmergeMe<T>::dataName;

template <typename T>
PmergeMe<T>::PmergeMe(int argc, char *input_list[])
    : List()
{
  if (argc < 2)
    throw PmergeMe::Error("Error: Invalid number of arguments.");

  for (int i = 1; i < argc; ++i)
  {
    char *endPtr = 0;
    errno = 0;

    long num = std::strtol(input_list[i], &endPtr, 10);

    if (*endPtr != '\0' || input_list[i][0] == '\0')
      throw PmergeMe::Error(
          "Error: Invalid token '" + std::string(input_list[i]) + "'.");
    if (errno == ERANGE)
      throw PmergeMe::Error(
          "Error: Number out of range '" + std::string(input_list[i]) + "'.");
    if (num < 0)
      throw PmergeMe::Error(
          "Error: Invalid number '" + std::string(input_list[i]) + "'.");
    if (num > INT_MAX)
      throw PmergeMe::Error("Error: Number exceeds INT_MAX '" + std::string(input_list[i]) + "'.");

    List.push_back(static_cast<size_t>(num));
  }
}

template <typename T>
PmergeMe<T>::PmergeMe(const PmergeMe &other)
    : List(other.List) {}

template <typename T>
PmergeMe<T> &PmergeMe<T>::operator=(const PmergeMe &other)
{
  if (this != &other)
  {
    List = other.List;
  }
  return *this;
}

template <typename T>
PmergeMe<T>::~PmergeMe() {}

template <typename T>
double PmergeMe<T>::getSortingTime() const
{
  return sorting_time;
}

template <typename T>
void PmergeMe<T>::sort()
{
  struct timeval start, end;
  gettimeofday(&start, NULL);

  sort_container(List);

  gettimeofday(&end, NULL);
  sorting_time =
      (end.tv_sec - start.tv_sec) * 1000000.0 +
      (end.tv_usec - start.tv_usec);
}

// Geters
template <typename T>
const T &PmergeMe<T>::getList() const
{
  return List;
}

template <typename T>
void PmergeMe<T>::display() const
{
  std::cout << "Time to process a range of " << List.size()
            << " elements with std::[" << container_name<T>::value << "] : " << sorting_time << " us" << std::endl;
}

// Overload operator<< for vector and deque , we can add more if needed
template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &vec)
{
  for (size_t i = 0; i < vec.size(); ++i)
  {
    if (i > 0)
      os << " ";
    os << vec[i];
  }
  return os;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::deque<T> &deq)
{
  for (size_t i = 0; i < deq.size(); ++i)
  {
    if (i > 0)
      os << " ";
    os << deq[i];
  }
  return os;
}

std::vector<std::pair<Integer, Integer> > creatPairs(const std::vector<Integer> &l);

std::vector<Integer> pushLargerElements(const std::vector<std::pair<Integer, Integer> > &pairs);

std::vector<std::pair<Integer, Integer> > rearrangePairs(
    const std::vector<Integer> &largerElements,
    const std::vector<std::pair<Integer, Integer> > &originalPairs,
    int lvl);

std::vector<Integer> creatMainChain(const std::vector<std::pair<Integer, Integer> > &sortedPairs);

std::vector<Integer> storeB(const std::vector<std::pair<Integer, Integer> > &sortedPairs,
                            bool hasLeftover,
                            const Integer &leftOver);

void binaryInsertion(size_t prevK, size_t K,
                     std::vector<Integer> &b_elements,
                     std::vector<Integer> &mainChain,
                     std::vector<size_t> &aPositions);

std::deque<std::pair<Integer, Integer> > creatPairs(const std::deque<Integer> &l);

std::deque<Integer> pushLargerElements(const std::deque<std::pair<Integer, Integer> > &pairs);

std::deque<std::pair<Integer, Integer> > rearrangePairs(
    const std::deque<Integer> &largerElements,
    const std::deque<std::pair<Integer, Integer> > &originalPairs,
    int lvl);

std::deque<Integer> creatMainChain(const std::deque<std::pair<Integer, Integer> > &sortedPairs);

std::deque<Integer> storeB(const std::deque<std::pair<Integer, Integer> > &sortedPairs,
                           bool hasLeftover,
                           const Integer &leftOver);

void binaryInsertion(size_t prevK, size_t K,
                     std::deque<Integer> &b_elements,
                     std::deque<Integer> &mainChain,
                     std::vector<size_t> &aPositions);

template <typename Container>
void PmergeMe<Container>::sort_container(std::deque<Integer> &l)
{
  static int lvl_deq = 0;
  lvl_deq++;
  if (l.size() <= 1)
  {
    lvl_deq--;
    return;
  }
  bool hasLeftover = (l.size() % 2 != 0);
  Integer leftOver = hasLeftover ? l.back() : Integer(0);
  std::deque<std::pair<Integer, Integer> > pairs = creatPairs(l);
  std::deque<Integer> largerElements = pushLargerElements(pairs);
  sort_container(largerElements);
  std::deque<std::pair<Integer, Integer> > sortedPairs = rearrangePairs(largerElements, pairs, lvl_deq);
  lvl_deq--;
  std::deque<Integer> mainChain = creatMainChain(sortedPairs);
  std::deque<Integer> b_elements = storeB(sortedPairs, hasLeftover, leftOver);

  std::vector<size_t> aPositions(b_elements.size());
  for (size_t i = 0; i < b_elements.size(); i++)
    aPositions[i] = i + 1;

  size_t prevK = 1;
  size_t jacobIdx = 2;
  while (prevK < b_elements.size())
  {
    size_t K = sequenceNext(jacobIdx);
    K = std::min(K, b_elements.size());
    binaryInsertion(prevK, K, b_elements, mainChain, aPositions);
    prevK = K;
    jacobIdx++;
  }
  l = mainChain;
}

//! The Algorithm I did immplemented is the Merge-Insertion or Ford-Johnson algorithm , as is described in the BOOK "The Art of Computer Programming" by Donald E.Knuth Vol 3
//? I did solved problmes like , save relaionships between pairs using backtracking info stored in each Integer object
//? and saving apositions using aPositions vector to avoid re-scanning the mainChain for each insertion

//!THIS IS THE FINAL RESULT : I am proud of it :)
template <typename Container>
void PmergeMe<Container>::sort_container(std::vector<Integer> &l)
{
  static int lvl = 0;
  lvl++;
  if (l.size() <= 1)
  {
    lvl--;
    return;
  }
  bool hasLeftover = (l.size() % 2 != 0);
  Integer leftOver = hasLeftover ? l.back() : Integer(0);
  //? Here I am creating pairs and sorting each pair then storing largest elements in a separate vector
  std::vector<std::pair<Integer, Integer> > pairs = creatPairs(l);
  std::vector<Integer> largerElements = pushLargerElements(pairs);
  //? Recursive call to sort the larger elements , using Merge-Insertion sort
  sort_container(largerElements);
  //? rearranging pairs using backtracking info stored as index in each Integer
  std::vector<std::pair<Integer, Integer> > sortedPairs = rearrangePairs(largerElements, pairs, lvl);
  //? decrementing recursion level , for correct index retrieval
  lvl--;
  //? Creating main chain from sorted pairs + first smallest element
  std::vector<Integer> mainChain = creatMainChain(sortedPairs);
  //? Storing smaller elements in b_elements vector
  std::vector<Integer> b_elements = storeB(sortedPairs, hasLeftover, leftOver);
  //? Preparing aPositions vector to track positions in mainChain
  std::vector<size_t> aPositions(b_elements.size());
  for (size_t i = 0; i < b_elements.size(); i++)
    aPositions[i] = i + 1;

  //? using Jacobsthal sequence to perform binary insertion of b_elements into mainChain, and the range to where to insert is tracked using aPositions
  size_t prevK = 1;
  size_t jacobIdx = 2;
  while (prevK < b_elements.size())
  {
    size_t K = sequenceNext(jacobIdx);
    K = std::min(K, b_elements.size());
    //? Perform binary insertion for the current range determined by Jacobsthal sequence
    binaryInsertion(prevK, K, b_elements, mainChain, aPositions);
    prevK = K;
    jacobIdx++;
  }
  //? after all recursions and insertions are done , we update the original list with the sorted mainChain
  l = mainChain;
}

#endif