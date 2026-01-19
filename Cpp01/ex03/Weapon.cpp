/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:32:58 by mbousset          #+#    #+#             */
/*   Updated: 2025/10/06 16:49:37 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string Weapon) :type(Weapon) { }

void Weapon::setType(std::string str)
{
    type = str;
}

const std::string& Weapon::getType()
{
    std::string &typeRef = type;
    return (typeRef);
}