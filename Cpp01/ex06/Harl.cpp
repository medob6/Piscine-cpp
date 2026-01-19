/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 16:23:19 by mbousset          #+#    #+#             */
/*   Updated: 2025/10/08 18:51:04 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {};

Harl::~Harl() {};

void Harl::debug(void){
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.I really do !\n"<< std::endl;
}

void Harl::info(void)
{
    std::cout << "I cannot believe adding extra bacon costs more money. \nYou didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "I think I deserve to have some extra bacon for free. \nI’ve been coming for years whereas you started working here since last month.\n" 
              << std::endl;
}

void Harl::error(void)
{
    std::cout << "This is unacceptable! I want to speak to the manager now.\n" << std::endl;
}

void Harl::invalid() {
    std::cout << "Harl: Invalid Action" << std::endl;
}

void Harl::complain(std::string level)
{
    std::string acts[5] = {"DEBUG", "INFO", "WARNING", "ERROR", "INVALID"};
    void (Harl::*actions[])(void) = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error, &Harl::invalid };

    int i = 0;
    while (i < 4 && acts[i] != level)
        i++;
    (this->*actions[i])();
}