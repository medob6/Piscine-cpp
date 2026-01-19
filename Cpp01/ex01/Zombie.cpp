/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 14:30:46 by mbousset          #+#    #+#             */
/*   Updated: 2025/10/06 15:50:01 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"



void Zombie::setName(std::string str) {name = str;}

Zombie::~Zombie(void) 
{
    std::cout << name << ": Grrrhhhhh... uhhrr... (destroyed)" << std::endl;
}

void Zombie::announce()
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..."<< std::endl;
}