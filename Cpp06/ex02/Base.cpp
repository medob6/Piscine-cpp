/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 09:16:20 by mbousset          #+#    #+#             */
/*   Updated: 2025/12/02 09:54:25 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {};

Base *generate()
{
  int r = std::rand();
  std::cout << "Generated random number: " << r << std::endl;

  if (r % 3 == 0)
    return new A();
  else if (r % 2 == 0)
    return new B();
  else
    return new C();
}

void identify(Base *p)
{
  if (dynamic_cast<A *>(p) != 0)
    std::cout << "Object of type A identified" << std::endl;
  else if (dynamic_cast<B *>(p) != 0)
    std::cout << "Object of type B identified" << std::endl;
  else if (dynamic_cast<C *>(p) != 0)
    std::cout << "Object of type C identified" << std::endl;
}

void identify(Base &p)
{
  try
  {
    A &a = dynamic_cast<A &>(p);
    (void)a;
    std::cout << "Object of type A identified" << std::endl;
    return;
  }
  catch (const std::exception &e)
  {
  }
  try
  {
    B &b = dynamic_cast<B &>(p);
    (void)b;
    std::cout << "Object of type B identified" << std::endl;
    return;
  }
  catch (const std::exception &e)
  {
  }
  try
  {
    C &c = dynamic_cast<C &>(p);
    (void)c;
    std::cout << "Object of type C identified" << std::endl;
    return;
  }
  catch (const std::exception &e)
  {
  }
}