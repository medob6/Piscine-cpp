/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 18:21:01 by mbousset          #+#    #+#             */
/*   Updated: 2025/10/18 11:10:26 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
    std::cout << "=== FragTrap Test Start ===" << std::endl;

    // Create a FragTrap
    FragTrap frag("Fraggy");

    std::cout << "\n--- Testing Attacks ---" << std::endl;
    frag.attack("Target Dummy");

    std::cout << "\n--- Testing Damage ---" << std::endl;
    frag.takeDamage(30);
    frag.takeDamage(80); // should bring HP to 0

    std::cout << "\n--- Testing Repair ---" << std::endl;
    frag.beRepaired(20); // will work only if HP > 0
    frag.beRepaired(10);

    std::cout << "\n--- Testing High Fives ---" << std::endl;
    frag.highFivesGuys();

    std::cout << "\n=== FragTrap Test End ===" << std::endl;
    return 0;
}
