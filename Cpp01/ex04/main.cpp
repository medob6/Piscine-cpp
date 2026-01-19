/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 17:42:02 by mbousset          #+#    #+#             */
/*   Updated: 2025/10/08 16:11:43 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

void  replace_s1_s2( std::string &line,const std::string &s1, const std::string &s2)
{
    size_t pos = 0;
    while ((pos = line.find(s1, pos)) != std::string::npos) {
        line.erase(pos, s1.length());
        line.insert(pos, s2);
        pos += s2.length();
    }
}

int main(int ac,char **av)
{
    if (ac != 4)
        return 1;
    std::string newfile;

    std::ifstream infile(av[1]);
    if (!infile) {
        std::cerr << "Error: could not open file for reading.\n";
        return 1;
    }
    newfile = std::string(av[1]) + ".replace";
    std::ofstream outfile(newfile.c_str());
    if (!outfile)
    {
        std::cerr << "Error: could not open file for writing.\n";
        return 1;
    }
    
    std::string line;
    while (std::getline(infile, line)) {
        replace_s1_s2(line,av[2],av[3]);
        outfile << line << std::endl;
    }
    infile.close();
    outfile.close();
    return 0;
}