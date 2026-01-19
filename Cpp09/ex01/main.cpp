/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 17:18:15 by mbousset          #+#    #+#             */
/*   Updated: 2025/12/18 18:24:24 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac,char *av[])
{
  try
  {
    RPN rpn(av[1], ac);
    rpn.processToken();
    std::cout << rpn.getResult() << std::endl;
  }
  catch (const RPN::Error &e)
  {
    std::cerr << e.what() << std::endl;
    return 1;
  }
  return 0;
}