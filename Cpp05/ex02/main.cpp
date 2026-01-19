/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 13:15:56 by mbousset          #+#    #+#             */
/*   Updated: 2025/11/28 09:04:55 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

void logHeader(const std::string &title)
{
    std::cout << "\n========== " << title << " ==========\n"
              << std::endl;
}

void trySign(Bureaucrat &b, AForm &f)
{
    std::cout << "[SIGN] " << b.getName() << " tries to sign " << f.getName() << std::endl;
    try
    {
        f.beSigned(b);
        std::cout << "  ✔ Sign success\n";
    }
    catch (const std::exception &e)
    {
        std::cout << "  ✘ Sign failed: " << e.what() << std::endl;
    }
}

void tryExecute(Bureaucrat &b, AForm &f)
{
    std::cout << "[EXECUTE] " << b.getName() << " tries to execute " << f.getName() << std::endl;
    try
    {
        f.execute(b);
        std::cout << "  ✔ Execute success\n";
    }
    catch (const std::exception &e)
    {
        std::cout << "  ✘ Execute failed: " << e.what() << std::endl;
    }
}

void tryExecuteForm(Bureaucrat &b, AForm &f)
{
    std::cout << "[executeForm()] " << b.getName() << " executes " << f.getName() << std::endl;
    try
    {
        b.executeForm(f);
    }
    catch (const std::exception &e)
    {
        std::cout << "  ✘ executeForm failed: " << e.what() << std::endl;
    }
}

int main()
{
    logHeader("Create Bureaucrats");
    Bureaucrat low("Low", 150);
    Bureaucrat mid("Mid", 100);
    Bureaucrat high("High", 1);

    logHeader("Create Forms");
    ShrubberyCreationForm shrub("home");
    RobotomyRequestForm robo("marvin");
    PresidentialPardonForm pres("Zaphod");

    // ------------------------------------------------------
    logHeader("Case 1 : Execute unsigned forms");
    tryExecute(low, shrub);
    tryExecute(mid, robo);
    tryExecute(high, pres);

    // ------------------------------------------------------
    logHeader("Case 2 : Try signing with too-low grade");
    trySign(low, shrub);
    trySign(low, robo);
    trySign(low, pres);

    // ------------------------------------------------------
    logHeader("Case 3 : Properly sign with mid/high bureaucrats");
    trySign(mid, shrub);
    trySign(mid, robo);  // should fail (robotomy requires grade 72)
    trySign(high, robo); // will succeed
    trySign(high, pres);

    // ------------------------------------------------------
    logHeader("Case 4 : Execute with too-low grade");
    tryExecute(low, shrub);
    tryExecute(mid, robo); // mid may fail if grade too low
    tryExecute(mid, pres); // definitely fails

    // ------------------------------------------------------
    logHeader("Case 5 : Successful executions");
    tryExecute(high, shrub);
    tryExecute(high, robo);
    tryExecute(high, pres);

    // ------------------------------------------------------
    logHeader("Case 6 : Execute via executeForm()");
    tryExecuteForm(low, shrub);
    tryExecuteForm(mid, robo);
    tryExecuteForm(high, pres);

    return 0;
}
