/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 14:44:10 by mbousset          #+#    #+#             */
/*   Updated: 2025/10/22 14:48:12 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    std::cout << "MateriaSource default constructor called\n";
    for (size_t i = 0; i < 4; i++)
        LearnedMateria[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource &other)
{
    std::cout << "MateriaSource copy constructor called\n";
    for (int i = 0; i < 4; i++)
    {
        delete LearnedMateria[i];
        if (other.LearnedMateria[i])
            LearnedMateria[i] = other.LearnedMateria[i]->clone();
        else
            LearnedMateria[i] = NULL;
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
    std::cout << "MateriaSource assignment operator called\n";
    if (this != &other)
    {
        for (int i = 0; i < 4; i++)
        {
            delete LearnedMateria[i];
            if (other.LearnedMateria[i])
                LearnedMateria[i] = other.LearnedMateria[i]->clone();
            else
                LearnedMateria[i] = NULL;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource()
{
    std::cout << "MateriaSource destructor called\n";
    for (size_t i = 0; i < 4; i++)
        delete LearnedMateria[i];
}

void MateriaSource::learnMateria(AMateria *m)
{
    if (!m)
        return;
    for (size_t i = 0; i < 4; i++)
    {
        if (!LearnedMateria[i])
        {
            LearnedMateria[i] = m->clone();
            delete m;
            return;
        }
    }
    delete m;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    for (size_t i = 0; i < 4; i++)
    {
        if (LearnedMateria[i] && LearnedMateria[i]->getType() == type)
            return (LearnedMateria[i]->clone());
    }
    return NULL;
}
