/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 10:39:27 by mbousset          #+#    #+#             */
/*   Updated: 2025/10/18 11:11:44 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// Default constructor
FragTrap::FragTrap()
    : ClapTrap("Unnamed FragTrap")
{
    HitPoints = 100;
    EnergyPoints = 100;
    AttackDamage = 30;
    std::cout << "FragTrap " << name << " constructed (default) 🤖" << std::endl;
}

// Parameterized constructor
FragTrap::FragTrap(const std::string &name)
    : ClapTrap(name)
{
    HitPoints = 100;
    EnergyPoints = 100;
    AttackDamage = 30;
    std::cout << "FragTrap " << name << " constructed 🎉" << std::endl;
}

// Copy constructor
FragTrap::FragTrap(const FragTrap &other)
    : ClapTrap(other)
{
    std::cout << "FragTrap " << name << " copied ⚙️" << std::endl;
}

// Copy assignment operator
FragTrap &FragTrap::operator=(const FragTrap &other)
{
    ClapTrap::operator=(other);
    std::cout << "FragTrap " << name << " assigned 🔁" << std::endl;
    return *this;
}
// Destructor
FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << name << " destructed 🔥" << std::endl;
}

void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap " << name 
              << " requests a positive high five! ✋" 
              << std::endl;
}