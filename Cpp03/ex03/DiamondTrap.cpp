/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 11:13:10 by mbousset          #+#    #+#             */
/*   Updated: 2025/10/19 10:49:11 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// Default constructor
DiamondTrap::DiamondTrap()
{
    name = "Default";
    ClapTrap::name = name + "_clap_name";
    HitPoints = FragTrap::HitPoints;     
    EnergyPoints = ScavTrap::EnergyPoints;
    AttackDamage = FragTrap::AttackDamage;
    std::cout << "DiamondTrap " << name << " constructed! 💎" << std::endl;
}

// Parameterized constructor
DiamondTrap::DiamondTrap(const std::string &n)
{
    name = n;
    ClapTrap::name = n + "_clap_name";
    HitPoints = FragTrap::HitPoints;     
    EnergyPoints = ScavTrap::EnergyPoints;
    AttackDamage = FragTrap::AttackDamage;
    std::cout << "DiamondTrap " << name << " constructed! 💎" << std::endl;
}

// Copy constructor
DiamondTrap::DiamondTrap(const DiamondTrap &other)
{
    *this = other;
    std::cout << "DiamondTrap " << name << " copied! 💎" << std::endl;
}

// Copy assignment operator
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
    if (this != &other)
    {
        ClapTrap::name = other.ClapTrap::name;
        name = other.name;
        HitPoints = other.HitPoints;
        EnergyPoints = other.EnergyPoints;
        AttackDamage = other.AttackDamage;
    }
    return *this;
}

// Destructor
DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << name << " destructed! 💥" << std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap name: " << name 
              << ", ClapTrap name: " << ClapTrap::name << std::endl;
}
