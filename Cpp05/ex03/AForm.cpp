/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:34:14 by mbousset          #+#    #+#             */
/*   Updated: 2025/11/23 18:48:46 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

void AForm::validateGrade(int grade) const
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

AForm::AForm() : name("default"), isSigned(false), gradeToSign(1), gradeToExecute(1) {}

AForm::AForm(const std::string &name, int signGrade, int execGrade)
    : name(name), isSigned(false), gradeToSign(signGrade), gradeToExecute(execGrade)
{
    validateGrade(signGrade);
    validateGrade(execGrade);
}

AForm::AForm(const AForm &other) : name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
    validateGrade(gradeToSign);
    validateGrade(gradeToExecute);
}

AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
    {
        this->isSigned = other.isSigned;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &os, const AForm &f)
{
    os << "AForm name: " << f.getName()
       << ", signed: " << (f.getIsSigned() ? "yes" : "no")
       << ", grade to sign: " << f.getGradeToSign()
       << ", grade to execute: " << f.getGradeToExecute();
    return os;
}

const std::string &AForm::getName() const
{
    return name;
}

bool AForm::getIsSigned() const
{
    return isSigned;
}

int AForm::getGradeToSign() const
{
    return gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return gradeToExecute;
}

void AForm::beSigned(Bureaucrat &b)
{
    if (b.getGrade() > this->gradeToSign)
        throw GradeTooLowException();
    std::cout << b.getName() << " signed " << name << std::endl;
    this->isSigned = true;
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "Form: grade is too low!";
}
const char *AForm::FormNotSignedException::what() const throw()
{
    return "Form: is not signed!";
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "Form: grade is too high!";
}