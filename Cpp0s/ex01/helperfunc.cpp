/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helperfunc.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 18:02:53 by mbousset          #+#    #+#             */
/*   Updated: 2025/10/15 15:36:37 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void Contact::setFirstName(const std::string &fn){ firstname = fn;}

void Contact::setLastName(const std::string &ln){ lastname = ln;}

void Contact::setNickName(const std::string &nn){ nickname = nn;}

void Contact::setPhoneNumber(const std::string &pn){ phonenumber = pn;}

void Contact::setSecret(const std::string &s){ secret = s;}


std::string Contact::getFirstName() const{ return firstname;}

std::string Contact::getLastName() const{ return lastname;}

std::string Contact::getNickName() const{ return nickname;}

std::string Contact::getPhoneNumber() const{ return phonenumber;}

std::string Contact::getSecret() const{ return secret;}

PhoneBook::PhoneBook()
{
    contactcount = 0;
}

bool only_spaces(const std::string& s)
{
    for (size_t i = 0; i < s.size(); ++i)
        if (!std::isspace(s[i]))
            return false;
    return true;
}

bool PhoneBook::addContact() {
    Contact& c = contacts[contactcount % 8];
    std::string input;

    std::cout << "Enter First Name: ";
    if (!std::getline(std::cin, input)) return false;
    if (input.empty() || only_spaces(input)) return true;
    c.setFirstName(input);
    
    std::cout << "Enter Last Name: ";
    if (!std::getline(std::cin, input)) return false;
    if (input.empty() || only_spaces(input)) return true;
    c.setLastName(input);

    std::cout << "Enter Nickname: ";
    if (!std::getline(std::cin, input)) return false;
    if (input.empty() || only_spaces(input)) return true;
    c.setNickName(input);

    std::cout << "Enter Phone Number: ";
    if (!std::getline(std::cin, input)) return false;
    if (input.empty() || only_spaces(input)) return true;
    c.setPhoneNumber(input);

    std::cout << "Enter Darkest Secret: ";
    if (!std::getline(std::cin, input)) return false;
    if (input.empty() || only_spaces(input)) return true;
    c.setSecret(input);

    ++contactcount;
    return true;
}

static int min(int a,int b)
{
    if (a < b)
        return (a);
    return (b);
}

static std::string intToString(int num) {
    std::ostringstream oss;
    oss << num;
    return oss.str();
}


static std::string formatField(const std::string &s)
{
    if (s.size() > 10)
        return (s.substr(0,9) + ".");
    std::ostringstream oss;
    oss << std::setw(10) << std::right << s;
    return oss.str();
}

void PhoneBook::displayContacts() const
{
    if (contactcount == 0)
    {
        std::cout << "No contacts to search. Please add a contact first." << std::endl;
        return;
    }
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "|" << formatField("Index")
              << "|" << formatField("First Name")
              << "|" << formatField("Last Name")
              << "|" << formatField("Nickname")
              << "|\n";
    std::cout << "---------------------------------------------" << std::endl; 
    for (int i = 0; i < min(8, contactcount);++i)
    {

    std::cout << "|" << formatField(intToString(i))
              << "|" << formatField(contacts[i].getFirstName())
              << "|" << formatField(contacts[i].getLastName())
              << "|" << formatField(contacts[i].getNickName())
              << "|\n";
    std::cout << "---------------------------------------------" << std::endl;
    }
    std::cout << "Enter contact index: ";
    std::string n;
    std::getline(std::cin, n);

    if (n.empty()) {
        std::cout << "   ---Unexsisting contact index.---\n";
        return;
    }

    std::istringstream iss(n);
    int index;
    if (!(iss >> index)) {
        std::cout << "    --Invalid contact index.--\n";
        return;
    }
    if (index < 0 || index >= min(8, contactcount)) {
        std::cout << "   ---Unexsisting contact index.---\n";
        return;
    }
    std::cout
        << "    Index      : " << formatField(intToString(index)) << std::endl
        << " First Name    : " << formatField(contacts[index].getFirstName()) << std::endl
        << " Last Name     : " << formatField(contacts[index].getLastName()) << std::endl
        << " Nickname      : " << formatField(contacts[index].getNickName()) << std::endl
        << " Phone Number  : " << formatField(contacts[index].getPhoneNumber()) << std::endl
        << " Darkest Secret: " << formatField(contacts[index].getFirstName()) << std::endl;
}
