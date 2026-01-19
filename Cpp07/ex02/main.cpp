/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 17:12:21 by mbousset          #+#    #+#             */
/*   Updated: 2025/12/04 18:06:34 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

struct Point
{
  int x, y;
};

// Helper functions for printing
void printInt(const int &x) { std::cout << x << " "; }
void printDouble(const double &x) { std::cout << x << " "; }
void printString(const std::string &s) { std::cout << "[" << s << "] "; }
void printPoint(const Point &p) { std::cout << "(" << p.x << "," << p.y << ") "; }

int main()
{
  std::cout << "===== Testing int Array =====" << std::endl;
  Array<int> intArr(5);
  for (size_t i = 0; i < intArr.size(); ++i)
    intArr[i] = i * 10;
  for (size_t i = 0; i < intArr.size(); ++i)
    printInt(intArr[i]);
  std::cout << std::endl;

  // Copy constructor
  Array<int> intCopy(intArr);
  std::cout << "Copied int array: ";
  for (size_t i = 0; i < intCopy.size(); ++i)
    printInt(intCopy[i]);
  std::cout << std::endl;

  // Assignment operator
  Array<int> intAssign;
  intAssign = intArr;
  std::cout << "Assigned int array: ";
  for (size_t i = 0; i < intAssign.size(); ++i)
    printInt(intAssign[i]);
  std::cout << std::endl;

  // Out-of-range test
  try
  {
    std::cout << "Accessing intArr[10]: \n";
    std::cout << intArr[10] << std::endl;
  }
  catch (const Array<int>::UnvalidIndex &e)
  {
    std::cerr << "Caught exception:" << e.what() << std::endl;
  }
  std::cout << "\n===== Testing double Array =====" << std::endl;
  Array<double> doubleArr(3);
  doubleArr[0] = 1.1;
  doubleArr[1] = 2.2;
  doubleArr[2] = 3.3;
  for (size_t i = 0; i < doubleArr.size(); ++i)
    printDouble(doubleArr[i]);
  std::cout << std::endl;

  std::cout << "\n===== Testing string Array =====" << std::endl;
  Array<std::string> strArr(3);
  strArr[0] = "foo";
  strArr[1] = "bar";
  strArr[2] = "baz";
  for (size_t i = 0; i < strArr.size(); ++i)
    printString(strArr[i]);
  std::cout << std::endl;

  std::cout << "\n===== Testing custom struct Array =====" << std::endl;
  Array<Point> points(3);
  points[0] = (Point){1, 2};
  points[1] = (Point){3, 4};
  points[2] = (Point){5, 6};
  for (size_t i = 0; i < points.size(); ++i)
    printPoint(points[i]);
  std::cout << std::endl;

  std::cout << "\n===== Testing empty Array =====" << std::endl;
  Array<int> emptyArr(0);
  std::cout << "Size of empty array: " << emptyArr.size() << std::endl;

  std::cout << "\n===== Testing single-element Array =====" << std::endl;
  Array<int> singleArr(1);
  singleArr[0] = 42;
  std::cout << "Single element: " << singleArr[0] << std::endl;

  return 0;
}
