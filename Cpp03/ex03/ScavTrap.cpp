/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 10:02:47 by mbousset          #+#    #+#             */
/*   Updated: 2025/10/18 10:17:19 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// Default constructor
ScavTrap::ScavTrap()
    : ClapTrap("Unnamed ScavTrap")
{
    HitPoints = 100;
    EnergyPoints = 50;
    AttackDamage = 20;
    std::cout << "ScavTrap " << name << " constructed (default) 🤖" << std::endl;
}

// Parameterized constructor
ScavTrap::ScavTrap(const std::string &name)
    : ClapTrap(name)
{
    HitPoints = 100;
    EnergyPoints = 50;
    AttackDamage = 20;
    std::cout << "ScavTrap " << this->name << " constructed 🛠️" << std::endl;
}

// Copy constructor
ScavTrap::ScavTrap(const ScavTrap &other)
    : ClapTrap(other)
{
    std::cout << "ScavTrap " << name << " copied ⚙️" << std::endl;
}

// Copy assignment operator
ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    ClapTrap::operator=(other);
    std::cout << "ScavTrap " << name << " assigned 🔁" << std::endl;
    return *this;
}

// Destructor
ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << name << " destroyed 💥" << std::endl;
}

// Overridden attack
void ScavTrap::attack(const std::string &target)
{
    if (HitPoints == 0)
    {
        std::cout << "ScavTrap " << name << " can’t attack — destroyed!" << std::endl;
        return;
    }
    if (EnergyPoints == 0)
    {
        std::cout << "ScavTrap " << name << " has no energy left to attack!" << std::endl;
        return;
    }

    std::cout << "ScavTrap " << name << " ferociously attacks " << target
              << ", dealing " << AttackDamage << " points of damage! ⚔️" << std::endl;
    EnergyPoints--;
}

// Unique method
void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << name << " is now in Gate Keeper mode 🛡️!" << std::endl;
}
