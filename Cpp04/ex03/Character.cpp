/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 13:37:49 by mbousset          #+#    #+#             */
/*   Updated: 2025/10/22 14:50:13 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : Name("UNKNOWN"), DropedItemsCount(0), FloorCapacity(10)
{
    std::cout << "Character default constructor called (Name=UNKNOWN)\n";
    Floor = new AMateria *[FloorCapacity];
    for (int i = 0; i < 4; ++i)
        Inventory[i] = NULL;
    for (int i = 0; i < FloorCapacity; ++i)
        Floor[i] = NULL;
}

Character::Character(std::string const &name) : Name(name), DropedItemsCount(0), FloorCapacity(10)
{
    std::cout << "Character parameterized constructor called (Name=" << name << ")\n";
    Floor = new AMateria *[FloorCapacity];
    for (int i = 0; i < 4; ++i)
        Inventory[i] = NULL;
    for (int i = 0; i < FloorCapacity; ++i)
        Floor[i] = NULL;
}

Character::Character(Character &other)
    : Name(other.Name), DropedItemsCount(other.DropedItemsCount), FloorCapacity(other.FloorCapacity)
{
    std::cout << "Character copy constructor called (Copying from: " << other.Name << ")\n";
    for (int i = 0; i < 4; ++i)
    {
        if (other.Inventory[i])
            Inventory[i] = other.Inventory[i]->clone();
        else
            Inventory[i] = NULL;
    }
    Floor = new AMateria *[FloorCapacity];
    for (int i = 0; i < FloorCapacity; ++i)
    {
        if (i < DropedItemsCount && other.Floor[i])
            Floor[i] = other.Floor[i]->clone();
        else
            Floor[i] = NULL;
    }
}

Character &Character::operator=(const Character &other)
{
    std::cout << "Character assignment operator called (Assigning from: " << other.Name << ")\n";
    if (this != &other)
    {
        Name = other.Name;

        for (int i = 0; i < 4; ++i)
        {
            delete Inventory[i];
            if (other.Inventory[i] != NULL)
                Inventory[i] = other.Inventory[i]->clone();
            else
                Inventory[i] = NULL;
        }
        for (int i = 0; i < DropedItemsCount; ++i)
            delete Floor[i];
        delete[] Floor;
        DropedItemsCount = other.DropedItemsCount;
        FloorCapacity = other.FloorCapacity;
        Floor = new AMateria *[FloorCapacity];
        for (int i = 0; i < FloorCapacity; ++i)
        {
            if (i < DropedItemsCount && other.Floor[i] != NULL)
                Floor[i] = other.Floor[i]->clone();
            else
                Floor[i] = NULL;
        }
    }
    return *this;
}

Character::~Character()
{
    std::cout << "Character destructor called (Name=" << Name << ")\n";
    for (int i = 0; i < 4; ++i)
        delete Inventory[i];
    for (int i = 0; i < DropedItemsCount; ++i)
        delete Floor[i];
    delete[] Floor;
}

std::string const &Character::getName() const
{
    return Name;
}

void Character::equip(AMateria *m)
{
    if (!m)
        return;
    for (int i = 0; i < 4; ++i)
    {
        if (Inventory[i] == m)
        {
            std::cerr << "Warning: Materia already equipped.\n";
            return;
        }
    }

    for (int i = 0; i < DropedItemsCount; ++i)
    {
        if (Floor[i] == m)
        {
            Floor[i] = Floor[DropedItemsCount - 1];
            Floor[DropedItemsCount - 1] = NULL;
            DropedItemsCount--;
            break;
        }
    }
    for (int i = 0; i < 4; ++i)
    {
        if (Inventory[i] == NULL)
        {
            Inventory[i] = m;
            return;
        }
    }
    if (DropedItemsCount >= FloorCapacity)
        resizeFloor();
    Floor[DropedItemsCount++] = m;
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx > 3 || !Inventory[idx])
        return;
    if (DropedItemsCount >= FloorCapacity)
        resizeFloor();
    Floor[DropedItemsCount++] = Inventory[idx];
    Inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
    if (idx < 0 || idx > 3 || !Inventory[idx])
        return;
    Inventory[idx]->use(target);
}

void Character::resizeFloor()
{
    int newCapacity = FloorCapacity * 2;
    AMateria **newFloor = new AMateria *[newCapacity];
    for (int i = 0; i < newCapacity; ++i)
    {
        if (i < DropedItemsCount)
            newFloor[i] = Floor[i];
        else
            newFloor[i] = NULL;
    }
    delete[] Floor;
    Floor = newFloor;
    FloorCapacity = newCapacity;
}
