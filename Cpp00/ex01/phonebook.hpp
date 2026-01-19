/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 10:40:32 by mbousset          #+#    #+#             */
/*   Updated: 2025/10/14 14:26:09 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"
#include <sstream>
#include <iomanip>

class PhoneBook {

    private:
        Contact contacts[8];
        int  contactcount;
    public:
        PhoneBook();
        bool  addContact();
        void displayContacts() const;
};

#endif
