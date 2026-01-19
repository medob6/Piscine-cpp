/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 09:14:27 by mbousset          #+#    #+#             */
/*   Updated: 2025/11/28 10:00:02 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "Intern created" << std::endl;
}

Intern::Intern(const Intern &other)
{
    (void)other;
}

Intern &Intern::operator=(const Intern &other)
{
    (void)other;
    return *this;
}

Intern::~Intern()
{
    std::cout << "Intern destroyed" << std::endl;
}

AForm *Intern::makeForm(std::string form_name, std::string target)
{
    const std::string names[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"};

    AForm *(*creators[3])(const std::string &) = {
        &createShrubbery,
        &createRobotomy,
        &createPresidential};

    for (int i = 0; i < 3; ++i)
    {
        if (form_name == names[i])
        {
            std::cout << "Intern creates " << form_name << std::endl;
            return creators[i](target);
        }
    }

    std::cout << "Intern could not find form \"" << form_name << "\"" << std::endl;
    return NULL;
}

AForm *Intern::createShrubbery(const std::string &target)
{
    return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomy(const std::string &target)
{
    return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidential(const std::string &target)
{
    return new PresidentialPardonForm(target);
}
