/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 08:41:02 by mbousset          #+#    #+#             */
/*   Updated: 2025/12/08 13:23:56 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <string>
#include <stack>
#include <queue>

void testVector()
{
  std::cout << "\n===== Testing vector =====" << std::endl;
  std::vector<int> v;
  v.push_back(10);
  v.push_back(20);
  v.push_back(30);

  try
  {
    // here i did test the case of a const container with readonly data , i cast it after cus you cant modify a const container , and i used static cast .
    // just a bonus learned from previos subject
    std::cout << "Found: " << *easyfind(static_cast<const std::vector<int> >(v), 20) << std::endl;
    std::cout << "Trying 99..." << std::endl;
    std::cout << *easyfind(v, 99) << std::endl;
  }
  catch (std::exception &e)
  {
    std::cout << "Exception: " << e.what() << std::endl;
  }
}

void testDeque()
{
  std::cout << "\n===== Testing deque =====" << std::endl;
  std::deque<int> d;
  d.push_back(5);
  d.push_back(15);
  d.push_back(25);

  try
  {
    std::cout << "Found: " << *easyfind(d, 25) << std::endl;
    std::cout << "Trying -1..." << std::endl;
    std::cout << *easyfind(d, -1) << std::endl;
  }
  catch (std::exception &e)
  {
    std::cout << "Exception: " << e.what() << std::endl;
  }
}

void testList()
{
  std::cout << "\n===== Testing list =====" << std::endl;
  std::list<int> lst;
  lst.push_back(1);
  lst.push_back(2);
  lst.push_back(3);

  try
  {
    std::cout << "Found: " << *easyfind(lst, 1) << std::endl;
    std::cout << "Trying 10..." << std::endl;
    std::cout << *easyfind(lst, 10) << std::endl;
  }
  catch (std::exception &e)
  {
    std::cout << "Exception: " << e.what() << std::endl;
  }
}

void testString()
{
  std::cout << "\n===== Testing string =====" << std::endl;
  std::string s = "hello world";

  try
  {
    std::cout << "Found: " << *easyfind(s, 'o') << std::endl;
    std::cout << "Trying 'x'..." << std::endl;
    std::cout << *easyfind(s, 'x') << std::endl;
  }
  catch (std::exception &e)
  {
    std::cout << "Exception: " << e.what() << std::endl;
  }
}

void testStack()
{
  std::cout << "\n===== Testing stack (should NOT work) =====" << std::endl;
  std::stack<int> st;
  st.push(10);
  st.push(20);

  //  std::cout << *easyfind(st, 10) << std::endl;
  std::cout << "std::stack has NO iterators → easyfind CANNOT work.\n";
}

void testQueue()
{
  std::cout << "\n===== Testing queue (should NOT work) =====" << std::endl;
  std::queue<int> q;
  q.push(10);
  q.push(20);

  std::cout << "std::queue has NO iterators → easyfind CANNOT work.\n";
}

void testPriorityQueue()
{
  std::cout << "\n===== Testing priority_queue (should NOT work) =====" << std::endl;
  std::priority_queue<int> pq;
  pq.push(10);
  pq.push(20);

  std::cout << "std::priority_queue has NO iterators → easyfind CANNOT work.\n";
}

void testArrayOfInts()
{
  std::cout << "\n===== Testing ArrayOfInts =====" << std::endl;
  int arr[] = {1, 2, 3, 4, 5, 6, 7};

  try
  {
    std::cout << "Found: " << *easyfind(arr, 4) << std::endl;
    std::cout << "Trying 99..." << std::endl;
    std::cout << *easyfind(arr, 99) << std::endl;
  }
  catch (std::exception &e)
  {
    std::cout << "Exception: " << e.what() << std::endl;
  }
}

int main()
{
  testVector();
  testDeque();
  testList();
  testString();
  testArrayOfInts();

  testStack();         // cannot work
  testQueue();         // cannot work
  testPriorityQueue(); // cannot work

  return 0;
}
