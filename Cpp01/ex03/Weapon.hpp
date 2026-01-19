/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:18:53 by mbousset          #+#    #+#             */
/*   Updated: 2025/10/06 17:00:58 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WEAPON_HPP
#define WEAPON_HPP
#include <iostream>

class Weapon{
    std::string type;
    public:
        Weapon(std::string);
        const std::string &getType();
        void setType(std::string type);
};

#endif