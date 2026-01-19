/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 16:20:49 by mbousset          #+#    #+#             */
/*   Updated: 2025/10/17 09:10:45 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
    Harl costumer;
    
    std::cout <<  "\n*****************************\n" <<std::endl;
    costumer.complain("DEBUG");
    std::cout <<  "\n*****************************\n" <<std::endl;
    costumer.complain("INFO");
    std::cout <<  "\n*****************************\n" <<std::endl;
    costumer.complain("WARNING");
    std::cout <<  "\n*****************************\n" <<std::endl;
    costumer.complain("ERROR");
    std::cout <<  "\n*****************************\n" <<std::endl;
    costumer.complain("something");
    std::cout <<  "\n*****************************\n" <<std::endl;
    return 0;
}