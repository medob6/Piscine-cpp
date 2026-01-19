/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 09:46:13 by mbousset          #+#    #+#             */
/*   Updated: 2025/10/22 14:46:49 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice") { std::cout << "Ice default constructor called\n"; }
Ice::Ice(const Ice &other) : AMateria(other.getType()) { std::cout << "Ice copy constructor called\n"; }
Ice &Ice::operator=(const Ice &other)
{
    std::cout << "Ice assignment operator called\n";
    (void)other;
    return *this;
}
Ice::~Ice() { std::cout << "Ice destructor called\n"; }

AMateria *Ice::clone() const
{
    return new Ice(*this);
}

void Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
