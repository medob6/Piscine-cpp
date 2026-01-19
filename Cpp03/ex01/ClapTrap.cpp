/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 18:21:30 by mbousset          #+#    #+#             */
/*   Updated: 2025/10/19 10:51:50 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap():name("Default"),HitPoints(10),EnergyPoints(10),AttackDamage(0) 
{std::cout << "ClapTrap " << name << " constructed (default)" << std::endl;}

ClapTrap::~ClapTrap()
{ std::cout << "ClapTrap " << name << " has been destroyed 💥" << std::endl;}

ClapTrap::ClapTrap(std::string Name):name(Name), HitPoints(10),EnergyPoints(10),AttackDamage(0)
{std::cout << "ClapTrap " << this->name << " constructed" << std::endl;}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) 
{
    if (this != &other)
    {
        name = other.name;
        HitPoints = other.HitPoints;
        EnergyPoints = other.EnergyPoints;
        AttackDamage = other.AttackDamage;
    }
    std::cout << "ClapTrap " << name << " assigned from another ClapTrap" << std::endl;
    return (*this);
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    *this = other;
    std::cout << "ClapTrap " << name << " copied from another ClapTrap" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (HitPoints == 0)
    {
        std::cout << "ClapTrap" << name << " is destroyed and cannot attack!" << std::endl;
        return;
    }
    if (EnergyPoints == 0)
    {
        std::cout << "ClapTrap" << name << " has no energy left to attack!" << std::endl;
        return;
    }
    EnergyPoints--;
    std::cout << "ClapTrap" << name << " attacks " << target << " causing " 
    << AttackDamage << " points of damage! " << std::endl;
    
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (HitPoints == 0)
    {
        std::cout << "ClapTrap" << name << " is already destroyed!" << std::endl;
        return;
    }
    if (amount >= HitPoints)
        HitPoints = 0;  
    else
        HitPoints -= amount;
    std::cout << "ClapTrap" << name << " took " << amount
              << " points of damage! " << "Remaining HP: " << HitPoints 
              << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (HitPoints == 0)
    {
        std::cout << "ClapTrap" << name << " is already destroyed and can’t take more damage!" << std::endl;
        return;
    }
    if (EnergyPoints == 0)
    {
        std::cout << "ClapTrap" << name << " has no energy left to repair!" << std::endl;
        return;
    }
    HitPoints += amount;
    EnergyPoints--;
    std::cout << "ClapTrap" << name << " repairs itself for " << amount << " HP! "
              << "Now has " << HitPoints << " HP and " << EnergyPoints << " energy points left."
              << std::endl;
}
