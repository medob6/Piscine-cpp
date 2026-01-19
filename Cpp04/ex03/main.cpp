/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 20:40:42 by mbousset          #+#    #+#             */
/*   Updated: 2025/10/22 16:01:24 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"

int main()
{
    std::cout << "===== Setup =====" << std::endl;

    // Materia Source
    IMateriaSource *src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    // Characters
    Character *alice = new Character("Alice");
    Character *bob = new Character("Bob");

    std::cout << "\n===== Creating Materias =====" << std::endl;
    AMateria *ice1 = src->createMateria("ice");
    AMateria *cure1 = src->createMateria("cure");
    AMateria *ice2 = src->createMateria("ice");
    AMateria *cure2 = src->createMateria("cure");
    AMateria *nullMateria = src->createMateria("unknown"); // should be nullptr

    std::cout << "\n===== Equip Materias =====" << std::endl;
    alice->equip(ice1);
    alice->equip(cure1);
    alice->equip(nullMateria); // nothing happens
    alice->equip(ice2);
    alice->equip(cure2); // should go to floor if inventory full

    std::cout << "\n===== Use Materias =====" << std::endl;
    for (int i = 0; i < 5; ++i)
        alice->use(i, *bob); // some may be invalid slots

    std::cout << "\n===== Unequip Materias =====" << std::endl;
    alice->unequip(0);
    alice->unequip(1);
    alice->unequip(1);   // unequip empty slot, nothing happens
    alice->use(0, *bob); // should do nothing
    alice->use(1, *bob); // should do nothing

    std::cout << "\n===== Re-equip from Floor =====" << std::endl;
    alice->equip(ice1); // removed from floor
    alice->equip(cure1);
    alice->equip(ice1);  // attempt duplicate equip, should warn
    alice->equip(cure1); // attempt duplicate equip, should warn
    alice->use(0, *bob);
    alice->use(1, *bob);

    std::cout << "\n===== Filling Inventory & Floor Expansion =====" << std::endl;
    for (int i = 0; i < 10; ++i)
        alice->equip(src->createMateria("ice")); // test floor resize

    std::cout << "\n===== Deep Copy Test =====" << std::endl;
    Character *copyAlice = new Character(*alice);
    alice->unequip(0);       // remove ice1
    alice->use(0, *bob);     // should do nothing
    copyAlice->use(0, *bob); // deep copy still has original materia

    std::cout << "\n===== Equip nullptr Test =====" << std::endl;
    alice->equip(NULL); // nothing happens

    std::cout << "\n===== Invalid Slot Usage =====" << std::endl;
    alice->use(-1, *bob);
    alice->use(100, *bob);
    alice->use(1000000, *bob);

    std::cout << "\n===== Cleanup =====" << std::endl;
    delete copyAlice;
    delete alice;
    delete bob;
    delete src;

    return 0;
}
