/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 16:20:49 by mbousset          #+#    #+#             */
/*   Updated: 2025/10/08 18:56:57 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

enum Levels
{
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    UNKNOWN
};

void harlMessage(std::string &level)
{
    Harl obj;
    Levels Harl_state = UNKNOWN;
    
    if (level == "DEBUG") Harl_state = DEBUG;
    else if (level == "INFO") Harl_state = INFO;
    else if (level == "WARNING") Harl_state = WARNING;
    else if (level == "ERROR") Harl_state = ERROR;
    
    switch (Harl_state)
    {
    case DEBUG:
        obj.complain("DEBUG");
    case INFO:
        obj.complain("INFO");
    case WARNING:
        obj.complain("WARNING");
    case ERROR:
        obj.complain("ERROR");
        break;
    default:
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    };
}

int main(int ac,char **av)
{
    if (ac != 2) {
        std::cerr << "Usage: ./harlFilter <LEVEL>\n";
        return 1;
    }
    std::string level = av[1];
    harlMessage(level);
    return 0;
}