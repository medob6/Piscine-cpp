/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 19:41:23 by mbousset          #+#    #+#             */
/*   Updated: 2025/11/28 10:06:17 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation", 145, 137), _target("default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery Creation", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), _target(other._target)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        this->_target = other._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    // Check signing and grades
    if (!getIsSigned())
        throw AForm::FormNotSignedException();

    if (executor.getGrade() > getGradeToExecute())
        throw AForm::GradeTooLowException();

    // File creation
    std::ofstream out;
    out.open((std::string(_target) + "_shrubbery").c_str());
    if (!out)
        throw std::runtime_error("Failed to create shrubbery file");

    out << "       _-_       \n"
           "    /~~   ~~\\   \n"
           " /~~         ~~\\\n"
           "{               }\n"
           " \\  _-     -_  /\n"
           "   ~  \\\\ //  ~ \n"
           "_- -   | | _- _ \n"
           "  _ -  | |   -_ \n"
           "      // \\\\      \n";

    out.close();
}
