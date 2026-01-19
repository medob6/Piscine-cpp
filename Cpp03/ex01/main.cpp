/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 18:21:01 by mbousset          #+#    #+#             */
/*   Updated: 2025/10/18 10:25:41 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
    std::cout << "=== Creating ClapTrap and ScavTrap ===" << std::endl;
    ClapTrap clap("Clappy");
    ScavTrap scav("Guardian");

    std::cout << "\n=== Testing Attacks ===" << std::endl;
    clap.attack("Bandit");
    scav.attack("Intruder");

    std::cout << "\n=== Testing Damage and Repair ===" << std::endl;
    clap.takeDamage(5);
    clap.beRepaired(3);

    scav.takeDamage(40);
    scav.beRepaired(20);

    std::cout << "\n=== Testing ScavTrap Special Mode ===" << std::endl;
    scav.guardGate();

    std::cout << "\n=== End of Simulation ===" << std::endl;
    return 0;
}
