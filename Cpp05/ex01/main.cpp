/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 13:15:56 by mbousset          #+#    #+#             */
/*   Updated: 2025/12/02 16:12:25 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

void section(const std::string &title)
{
    std::cout << "\n========== " << title << " ==========\n";
}

int main()
{

    Form a("ABDAEL-M", 50, 25);

    std::cout << a.getName() << std::endl;

    std::string *hack = (std::string *)(&a.getName());
    *hack = "CHANGED_NAME";

    std::cout << a.getName() << std::endl;
}
