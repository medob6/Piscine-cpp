/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 09:33:03 by mbousset          #+#    #+#             */
/*   Updated: 2025/10/22 14:42:11 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : type("amateria")
{
    std::cout << "AMateria default constructor called\n";
}

AMateria::AMateria(std::string const &type) : type(type)
{
    std::cout << "AMateria param constructor called with type: " << this->type << std::endl;
}

AMateria::AMateria(AMateria &other) : type(other.type)
{
    std::cout << "AMateria copy constructor called from type: " << other.type << std::endl;
}

AMateria &AMateria::operator=(const AMateria &other)
{
    std::cout << "AMateria assignment operator called\n";
    if (this != &other)
        type = other.type;
    return (*this);
}

AMateria::~AMateria()
{
    std::cout << "AMateria destructor called for type: " << this->type << std::endl;
}

std::string const &AMateria::getType() const { return type; };

void AMateria::use(ICharacter &target)
{
    (void)target;
}
