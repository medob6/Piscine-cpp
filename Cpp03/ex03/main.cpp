/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 11:13:05 by mbousset          #+#    #+#             */
/*   Updated: 2025/10/18 14:40:25 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap d("Diamondy");

    d.attack("a target");
    d.takeDamage(30);
    d.beRepaired(20);
    d.whoAmI();

    return 0;
}
