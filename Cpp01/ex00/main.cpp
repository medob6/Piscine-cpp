/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 08:39:12 by mbousset          #+#    #+#             */
/*   Updated: 2025/10/17 11:24:45 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void let_us_announce1(Zombie *z)
{
    delete z;
    std::cout << "Vercingetorix just drank the sacred druid elixir." << std::endl;
    std::cout << "Vercingetorix now is CúChulainn!" << std::endl;
    z = new Zombie("constantine The Great");
    delete z;
}

void let_us_announce0(Zombie &z)
{
    z.announce();
}

int main()
{
    Zombie z0("Boudica");
    Zombie *z1 = newZombie("Vercingetorix");
    Zombie z2("Conn_of_the_Hundred_Battles");
    
    Zombie &refz0 = z0;
    Zombie *&refz1 = z1;

    let_us_announce0(refz0);
    let_us_announce1(refz1);
    randomChump("Nuada");

    std::cout << "May their names rest forever among the hills of Ériu." << std::endl;
    z1->announce();
    delete z1;
    return (0);
}
