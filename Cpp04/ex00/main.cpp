/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 11:56:56 by mbousset          #+#    #+#             */
/*   Updated: 2025/10/22 14:23:43 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main() {
    std::cout << "========== Correct Version ==========\n";
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); // Cat
    j->makeSound(); // Dog
    meta->makeSound(); // Generic animal sound

    delete meta;
    delete j;
    delete i;

    std::cout << "\n========== Wrong Version ==========\n";
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongI = new WrongCat();

    std::cout << wrongI->getType() << " " << std::endl;
    wrongI->makeSound();
    wrongMeta->makeSound();

    delete wrongMeta;
    delete wrongI;

    std::cout << "\n========== Direct Object Test (WrongCat) ==========\n";
    WrongCat wc;
    wc.makeSound(); 

    std::cout << "\n========== Slicing Test ==========\n";
    WrongCat wc2;
    WrongAnimal wa2 = wc2;
    wa2.makeSound(); 

    return 0;
}
