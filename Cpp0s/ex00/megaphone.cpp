/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 17:30:28 by mbousset          #+#    #+#             */
/*   Updated: 2025/10/15 14:22:01 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

std::string capitlize_str(char **av)
{
    std::string res;
    for (int i = 1; av[i]; ++i)
    {
        for (int j = 0;av[i][j]; ++j)
            res += std::toupper(av[i][j]);
    }
    return res;
}

int main(int ac,char **av)
{
    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
       std::cout << capitlize_str(av) << std::endl;
    return 0;
}
