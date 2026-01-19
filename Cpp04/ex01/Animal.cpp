/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 12:13:26 by mbousset          #+#    #+#             */
/*   Updated: 2025/10/22 14:27:16 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"


Animal::Animal() : type("UNKNOWN") {std::cout << "Animal default constructor called." << std::endl;}

Animal::Animal(const Animal &other) :type(other.type) {
    std::cout << "Animal copy constructor called." << std::endl;
}

Animal &Animal::operator=(const Animal &other) {
    std::cout << "Animal assignment operator called." << std::endl;
    if (this != &other)
        this->type = other.type;
    return *this;
}

Animal::~Animal() {
    std::cout << "Animal destructor called." << std::endl;
}

const std::string &Animal::getType() const {
    return type;
}

void Animal::makeSound() const {
    std::cout << "Generic animal sound." << std::endl;
}
