/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 15:29:51 by mbousset          #+#    #+#             */
/*   Updated: 2025/12/08 13:36:21 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

#include <iostream>
#include <list>

int main()
{
  std::cout << "=== MutantStack Example ===" << std::endl;
  MutantStack<int> mstack;
  mstack.push(5);
  mstack.push(17);

  std::cout << "Top: " << mstack.top() << std::endl;
  mstack.pop();
  std::cout << "Size: " << mstack.size() << std::endl;

  mstack.push(3);
  mstack.push(5);
  mstack.push(737);
  mstack.push(0);

  // std::cout << "some thing : " << *(mstack.begin() + 2);

  MutantStack<int>::iterator it = mstack.begin();
  MutantStack<int>::iterator ite = mstack.end();

  ++it;
  --it;

  std::cout << "MutantStack iteration:" << std::endl;
  while (it != ite)
  {
    std::cout << *it << std::endl;
    ++it;
  }

  std::stack<int> s1(mstack);

  std::cout << "\n=== std::list Example ===" << std::endl;
  std::list<int> lstack;
  lstack.push_back(5);
  lstack.push_back(17);

  std::cout << "Back: " << lstack.back() << std::endl;
  lstack.pop_back();
  std::cout << "Size: " << lstack.size() << std::endl;

  lstack.push_back(3);
  lstack.push_back(5);
  lstack.push_back(737);
  lstack.push_back(0);

  std::list<int>::iterator lit = lstack.begin();
  std::list<int>::iterator lite = lstack.end();

  ++lit;
  --lit;

  std::cout << "std::list iteration:" << std::endl;
  while (lit != lite)
  {
    std::cout << *lit << std::endl;
    ++lit;
  }

  std::stack<int, std::list<int> > s2(lstack);

  return 0;
}