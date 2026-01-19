/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 18:21:01 by mbousset          #+#    #+#             */
/*   Updated: 2025/10/19 11:35:48 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    
    // Create two ClapTraps
    ClapTrap clap1("Clappy");
    ClapTrap clap2("Trapster");
    
    

    std::cout << std::endl;

    // Attack sequence
    clap1.attack("Trapster");
    clap2.takeDamage(3);

    std::cout << std::endl;

    // Repair sequence
    clap2.beRepaired(5);

    std::cout << std::endl;

    // Energy exhaustion test
    for (int i = 0; i < 10; ++i)
        clap1.attack("Trapster");

    std::cout << std::endl;

    // Destroyed ClapTrap test
    clap2.takeDamage(100);
    clap2.attack("Clappy");  // Should fail (destroyed)
    clap2.beRepaired(10);    // Should fail (destroyed)

    std::cout << std::endl;

    return 0;
}

