/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:46:58 by mbousset          #+#    #+#             */
/*   Updated: 2025/12/18 15:35:20 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// void print(std::pair<std::string, float> pair)
// {

//   std::string str;
//   std::ostringstream out;
//   out << std::fixed << std::setprecision(2) << pair.first << "," << pair.second;
//   str = out.str();
// std::string fr = str.substr(str.find('.'));
// std::string res = str.substr(0, str.find('.')) + fr.substr(0, fr.find('0'));
// for (int i = str.length() - 1; (str[i] == '0' || str[i] == '.') && i > 0; i--)
// {
//   if (str[i] == '.')
//   {
//     str.erase(i, 1);
//     break;
//   }
//   str.erase(i, 1);
// }
// std::cout << str << '\n';
// }

BitcoinExchange::BitcoinExchange()
{
  std::ifstream DataBase("data.csv");
  if (!DataBase)
    throw BitcoinExchange::Error("Error: could not load database.");

  std::string line;
  std::getline(DataBase, line);

  if (line != "date,exchange_rate")
    throw BitcoinExchange::Error("Error: database is corrupted.");

  while (std::getline(DataBase, line))
  {
    std::string date = line.substr(0, 10);
    std::string valueStr = line.substr(11);

    double value = std::strtod(valueStr.c_str(), NULL);

    Exchange_RPY[date] = value;
  }

  // std::for_each(Exchange_RPY.begin(), Exchange_RPY.end(), print);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
    : Exchange_RPY(other.Exchange_RPY)
{
}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
  if (this != &other)
  {
    this->Exchange_RPY = other.Exchange_RPY;
  }
  return *this;
}
BitcoinExchange::~BitcoinExchange() {}
