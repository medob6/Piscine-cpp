/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 10:10:27 by mbousset          #+#    #+#             */
/*   Updated: 2025/10/22 14:38:53 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
private:
    std::string Name;
    AMateria *Inventory[4];
    AMateria **Floor;
    int DropedItemsCount;
    int FloorCapacity;

public:
    Character();
    Character(std::string const &name);
    Character(Character &other);
    Character &operator=(const Character &other);
    ~Character();

    std::string const &getName() const;
    void equip(AMateria *m);
    void unequip(int idx);
    void use(int idx, ICharacter &target);
    void resizeFloor();
};

#endif