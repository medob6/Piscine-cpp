/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 14:27:19 by mbousset          #+#    #+#             */
/*   Updated: 2025/10/22 14:27:30 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
    type = "Cat";
    std::cout << "Cat default constructor called." << std::endl;
    CatBrain = new Brain();
}

Cat::Cat(const Cat &other) : Animal(other)
{
    CatBrain = new Brain(*other.CatBrain);
    std::cout << "Cat copy constructor called." << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
    std::cout << "Cat assignment operator called." << std::endl;
    if (this != &other)
    {
        Animal::operator=(other);
        delete CatBrain;
        CatBrain = new Brain(*other.CatBrain);
    }
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called." << std::endl;
    delete CatBrain;
}

void Cat::makeSound() const
{
    std::cout << "Meow! Meow!" << std::endl;
}

Brain *Cat::getBrain() const
{
    return CatBrain;
}
