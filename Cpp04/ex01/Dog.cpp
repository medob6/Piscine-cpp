/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 14:26:03 by mbousset          #+#    #+#             */
/*   Updated: 2025/10/22 14:26:09 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
    type = "Dog";

    std::cout << "Dog default constructor called." << std::endl;
    DogBrain = new Brain();
}

Dog::Dog(const Dog &other) : Animal(other)
{
    DogBrain = new Brain(*other.DogBrain);
    std::cout << "Dog copy constructor called." << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
    std::cout << "Dog assignment operator called." << std::endl;
    if (this != &other)
    {
        Animal::operator=(other);
        delete DogBrain;
        DogBrain = new Brain(*other.DogBrain);
    }
    return *this;
}

Dog::~Dog()
{
    delete DogBrain;
    std::cout << "Dog destructor called." << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Haw! Haw!" << std::endl;
}

Brain *Dog::getBrain() const
{
    return DogBrain;
}
