/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:44:04 by mbousset          #+#    #+#             */
/*   Updated: 2025/10/06 17:39:21 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string str) :name(str), weapon(NULL){}

void HumanB::setWeapon(Weapon &w)
{
    this->weapon = &w;
}

void HumanB::attack()
{
    if (!weapon)
        std::cout << "no weapons can't attack" << std::endl;
    else
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}