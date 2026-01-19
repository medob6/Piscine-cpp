/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 10:42:15 by mbousset          #+#    #+#             */
/*   Updated: 2025/10/02 15:26:36 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"


int main()
{
    PhoneBook phonebook;
    std::string command;

    std::cout << "========================================\n";
    std::cout << "   📞  Welcome to the PhoneBook Software\n";
    std::cout << "========================================\n";
    std::cout << "Available commands:\n";
    std::cout << "   - ADD    : Add a new contact\n";
    std::cout << "   - SEARCH : Search for a contacts\n";
    std::cout << "   - EXIT   : Exit the program\n";
    std::cout << "----------------------------------------\n";
    
    std::cout << " > ";
    while (std::getline(std::cin , command))
    {
        if (command == "ADD")
        {
            if (!phonebook.addContact())
                return (0);
        }
        else if (command == "SEARCH")
            phonebook.displayContacts();
        else if (command == "EXIT")
        {
            std::cout << "Exiting PhoneBook. Goodbye! 👋\n";
            break;
        }
        else
            std::cout << "Invalid command. Please try again.\n";
        std::cout << " > ";
    }
        
    return (0);
}
