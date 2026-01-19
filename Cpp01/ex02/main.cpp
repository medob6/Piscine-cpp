/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:03:45 by mbousset          #+#    #+#             */
/*   Updated: 2025/10/06 16:13:04 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string *strPtr = &str;
    std::string &strRef = str;

    std::cout << &str << std::endl;
    std::cout << strPtr << std::endl;
    std::cout << &strRef << std::endl;

    std::cout << str << std::endl;
    std::cout << *strPtr << std::endl;
    std::cout << strRef << std::endl;

    return 0;
}