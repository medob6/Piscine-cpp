/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 09:46:23 by mbousset          #+#    #+#             */
/*   Updated: 2025/10/22 14:45:33 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
    std::cout << "Cure default constructor called\n";
}
Cure::Cure(const Cure &other) : AMateria(other.getType()) { std::cout << "Cure copy constructor called\n"; }
Cure &Cure::operator=(const Cure &other)
{
    std::cout << "Cure assignment operator called\n";
    (void)other;
    return *this;
}
Cure::~Cure() { std::cout << "Cure destructor called\n"; }

AMateria *Cure::clone() const
{
    return new Cure(*this);
}

void Cure::use(ICharacter &target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
