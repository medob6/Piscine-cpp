/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:23:59 by mbousset          #+#    #+#             */
/*   Updated: 2025/10/14 14:25:55 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <cctype>

class Contact{
    private:
        std::string firstname;
        std::string lastname;
        std::string nickname;
        std::string phonenumber;
        std::string secret;
    public:
    
        void setFirstName(const std::string &fn);
        void setLastName(const std::string &ln);
        void setNickName(const std::string &nn);
        void setPhoneNumber(const std::string &pn);
        void setSecret(const std::string &s);
        
        std::string getFirstName() const;
        std::string getLastName() const;
        std::string getNickName() const;
        std::string getPhoneNumber() const;
        std::string getSecret() const;
};

#endif