/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 09:08:28 by mbousset          #+#    #+#             */
/*   Updated: 2025/12/03 18:35:49 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int main()
{
  std::srand(static_cast<unsigned int>(std::time(0)));
  Base *pb = generate();

  identify(pb);
  delete pb;
  pb = generate();
  identify(*pb);

  delete pb;
  return 0;
}
