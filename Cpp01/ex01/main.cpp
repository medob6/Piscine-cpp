/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 08:39:12 by mbousset          #+#    #+#             */
/*   Updated: 2025/10/06 15:49:54 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"



int main()
{
    int N = 5;
    Zombie* Zombies = zombieHorde(N, "FRID");

    for (int i = 0; i < N; ++i)
        Zombies[i].announce();

    delete[] Zombies;
    return 0;
}
