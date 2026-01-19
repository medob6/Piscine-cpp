/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 11:56:56 by mbousset          #+#    #+#             */
/*   Updated: 2025/10/22 14:34:14 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main()
{
    const int SIZE = 4;
    Animal* animals[SIZE];
    
    // cant creat an instance of Animal cus animal is an Abstract class
    
    // Animal x;
    // x.makeSound();

    std::cout << "===== Creating Animals =====" << std::endl;
    for (int i = 0; i < SIZE; i++)
    {
        if (i < SIZE / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    std::cout << "\n===== Making Sounds =====" << std::endl;
    for (int i = 0; i < SIZE; i++)
        animals[i]->makeSound();  // Polymorphism in action

    std::cout << "\n===== Testing Deep Copy (Copy Constructor) =====" << std::endl;
    Dog originalDog;
    originalDog.getBrain()->setIdea(0, "Chase the cat!");
    Dog copiedDog(originalDog); // copy constructor

    std::cout << "Original Dog idea[0]: " << originalDog.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copied Dog idea[0]:   " << copiedDog.getBrain()->getIdea(0) << std::endl;

    copiedDog.getBrain()->setIdea(0, "Sleep all day.");
    std::cout << "\nAfter modifying copiedDog:" << std::endl;
    std::cout << "Original Dog idea[0]: " << originalDog.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copied Dog idea[0]:   " << copiedDog.getBrain()->getIdea(0) << std::endl;

    std::cout << "\n===== Testing Deep Copy (Assignment Operator) =====" << std::endl;
    Cat originalCat;
    originalCat.getBrain()->setIdea(0, "Scratch furniture!");
    Cat assignedCat;
    assignedCat = originalCat; // assignment operator

    std::cout << "Original Cat idea[0]: " << originalCat.getBrain()->getIdea(0) << std::endl;
    std::cout << "Assigned Cat idea[0]: " << assignedCat.getBrain()->getIdea(0) << std::endl;

    originalCat.getBrain()->setIdea(0, "Climb the curtains!");
    std::cout << "\nAfter modifying originalCat:" << std::endl;
    std::cout << "Original Cat idea[0]: " << originalCat.getBrain()->getIdea(0) << std::endl;
    std::cout << "Assigned Cat idea[0]: " << assignedCat.getBrain()->getIdea(0) << std::endl;

    std::cout << "\n===== Deleting Animals =====" << std::endl;
    for (int i = 0; i < SIZE; i++)
        delete animals[i];

    return 0;
}