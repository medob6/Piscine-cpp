/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 13:15:56 by mbousset          #+#    #+#             */
/*   Updated: 2025/11/29 08:36:26 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    std::cout << "========== Create Bureaucrats ==========" << std::endl;
    Bureaucrat low("Low", 150);
    Bureaucrat mid("Mid", 100);
    Bureaucrat high("High", 1);

    std::cout << "\n========== Create Intern ==========" << std::endl;
    Intern someRandomIntern;

    std::cout << "\n========== Make Forms ==========" << std::endl;

    AForm *form1 = someRandomIntern.makeForm("shrubbery creation", "Home");
    AForm *form2 = someRandomIntern.makeForm("robotomy request", "Bender");
    AForm *form3 = someRandomIntern.makeForm("presidential pardon", "Zaphod");
    AForm *form4 = someRandomIntern.makeForm("unknown form", "Target"); // should fail

    std::cout << "\n========== Test Execution ==========" << std::endl;

    // Execute ShrubberyCreationForm
    if (form1)
    {
        try
        {
            mid.signForm(*form1);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
        try
        {
            high.executeForm(*form1);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }

    // Execute RobotomyRequestForm
    if (form2)
    {
        try
        {
            high.signForm(*form2);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
        try
        {
            high.executeForm(*form2);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }

    // Execute PresidentialPardonForm
    if (form3)
    {
        try
        {
            high.signForm(*form3);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
        try
        {
            high.executeForm(*form3);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }

    // Clean up
    delete form1;
    delete form2;
    delete form3;
    delete form4; // nullptr safe

    std::cout << "\n========== End of Main ==========" << std::endl;
    return 0;
}
