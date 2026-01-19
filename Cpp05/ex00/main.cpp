/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 13:15:56 by mbousset          #+#    #+#             */
/*   Updated: 2025/11/29 09:07:31 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat b1;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Bureaucrat b2("ahmed", 60);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Bureaucrat b3("morad", 1); // should throw: too high
        b3.increment();
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Bureaucrat b4("zayd", 151); // should throw: too low
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    Bureaucrat be("khamis", 12);
    std::cout << be << std::endl;

    try
    {
        Bureaucrat b5("zaydon", 1200);
    }
    catch (std::exception e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "Goodbye sir/madam" << std::endl;
    return 0;
}
