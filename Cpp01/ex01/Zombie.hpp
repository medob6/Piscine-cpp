/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 08:39:40 by mbousset          #+#    #+#             */
/*   Updated: 2025/10/06 15:50:03 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>


class Zombie {
    
    private:
        std::string name;

    public:
        ~Zombie();
        void announce(void);
        void setName(std::string s);

};

Zombie *zombieHorde(int N, std::string name);

#endif