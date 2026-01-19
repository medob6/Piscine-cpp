/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:43:53 by mbousset          #+#    #+#             */
/*   Updated: 2025/10/06 17:28:03 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB{
    std::string name;
    Weapon *weapon;
    public:
        HumanB(std::string str);
        void attack();
        void setWeapon(Weapon &w);
};

#endif