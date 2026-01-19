/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 08:39:40 by mbousset          #+#    #+#             */
/*   Updated: 2025/10/06 14:31:17 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>


class Zombie {
    private:
        std::string name;

    public:
        Zombie(std::string s);
        ~Zombie();
        void announce(void);
};


Zombie* newZombie( std::string name );
void    randomChump(std::string name);

#endif