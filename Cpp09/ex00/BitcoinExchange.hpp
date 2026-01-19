/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:47:00 by mbousset          #+#    #+#             */
/*   Updated: 2025/12/18 15:35:29 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <iostream>
#include <exception>
#include <map>
#include <fstream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <cctype>

class BitcoinExchange
{

private:
  std::map<std::string, float> Exchange_RPY;
  std::ifstream infile;

public:
  // canonical form
  BitcoinExchange();
  BitcoinExchange(const BitcoinExchange &other);
  BitcoinExchange &operator=(const BitcoinExchange &other);
  ~BitcoinExchange();

  // exception classes
  class Error : public std::runtime_error
  {
  public:
    explicit Error(const std::string &msg) : std::runtime_error(msg) {}
  };

  // additionale methodes
  void validate_input(int arg_count, const char *input_file);
  void process_input(void);
  double get_exchangeRate(const std::string &Date);
};

#endif