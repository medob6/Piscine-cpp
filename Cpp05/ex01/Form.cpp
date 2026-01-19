/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:34:14 by mbousset          #+#    #+#             */
/*   Updated: 2025/11/29 08:48:16 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

void Form::validateGrade(int grade) const
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

Form::Form() : name("default"), isSigned(false), gradeToSign(1), gradeToExecute(1) {}

Form::Form(const std::string &name, int signGrade, int execGrade)
    : name(name), isSigned(false), gradeToSign(signGrade), gradeToExecute(execGrade)
{
    validateGrade(signGrade);
    validateGrade(execGrade);
}

Form::Form(const Form &other) : name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
    validateGrade(gradeToSign);
    validateGrade(gradeToExecute);
}

Form &Form::operator=(const Form &other)
{
    if (this != &other)
    {
        this->isSigned = other.isSigned;
    }
    return *this;
}

Form::~Form() {}

std::ostream &operator<<(std::ostream &os, const Form &f)
{
    os << "Form name: " << f.getName()
       << ", signed: " << (f.getIsSigned() ? "yes" : "no")
       << ", grade to sign: " << f.getGradeToSign()
       << ", grade to execute: " << f.getGradeToExecute();
    return os;
}

const std::string &Form::getName() const
{
    return name;
}

bool Form::getIsSigned() const
{
    return isSigned;
}

int Form::getGradeToSign() const
{
    return gradeToSign;
}

int Form::getGradeToExecute() const
{
    return gradeToExecute;
}

void Form::beSigned(Bureaucrat &b)
{
    if (b.getGrade() > this->gradeToSign)
        throw GradeTooLowException();
    this->isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Form: grade is too high!";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Form: grade is too low!";
}