/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:47:25 by mbousset          #+#    #+#             */
/*   Updated: 2025/12/18 16:55:11 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#define FRACTION 5

bool value_is_valid(const std::string &s)
{
  if (s.empty())
    return false;
  if (s[0] == '-')
    throw BitcoinExchange::Error("Error: not a positive number.");

  size_t i = (s[0] == '+');
  size_t dot = s.find('.');

  // Check for leading or trailing dot (when dot exists)
  if (dot != std::string::npos && (dot == i || dot == s.size() - 1))
    return false;

  // Check for invalid characters
  if (s.find_first_not_of("0123456789.", i) != std::string::npos)
    return false;

  // Check for multiple dots
  if (dot != std::string::npos && dot != s.rfind('.'))
    return false;

  // Convert to double and check range
  char *endptr;
  double val = strtod(s.c_str() + i, &endptr);
  if (*endptr != '\0' || val > 1000.0)
    throw BitcoinExchange::Error("Error: too large a number.");

  return true;
}

bool line_break_is_valid(const std::string &s)
{
  if (s == " | ")
    return true;
  return false;
}
bool date_is_valid(const std::string &s)
{
  if (std::count(s.begin(), s.end(), '-') != 2)
    return false;
  if (s[4] != '-' || s[7] != '-')
    return false;
  if (s.find_first_not_of("0123456789-", 0) != std::string::npos)
    return false;
  if (strtol(s.substr(5, 2).c_str(), NULL, 10) > 12 || strtol(s.substr(8, 2).c_str(), NULL, 10) > 31)
  {
    return false;
  }
  return true;
}

void line_valid(const std::string &line)
{
  if (line.size() < 14)
    throw BitcoinExchange::Error("Error: bad input => " + line);

  if (!date_is_valid(line.substr(0, 10)))
    throw BitcoinExchange::Error("Error: bad input => " + line);

  if (!line_break_is_valid(line.substr(10, 3)))
    throw BitcoinExchange::Error("Error: bad input => " + line);

  if (!value_is_valid(line.substr(13)))
    throw BitcoinExchange::Error("Error: bad input => " + line);
}

bool file_valid(std::ifstream &infile)
{
  std::string line;
  std::getline(infile, line);
  if (line != "date | value")
    return false;
  return true;
}

void BitcoinExchange::validate_input(int arg_count, const char *input_file)
{
  if (arg_count < 2)
    throw BitcoinExchange::Error("Error: could not open file.");
  infile.open(input_file);
  if (!infile)
    throw BitcoinExchange::Error("Error: could not open file.");
  if (!file_valid(infile))
    throw BitcoinExchange::Error("Error: Unvalid input file.");
}

double BitcoinExchange::get_exchangeRate(const std::string &Date)
{
  if (Exchange_RPY.empty())
    throw BitcoinExchange::Error("Error: exchange rate database is empty.");
  std::map<std::string, float>::iterator it = Exchange_RPY.lower_bound(Date);
  if (it == Exchange_RPY.end())
    --it;
  else if (it->first != Date && it != Exchange_RPY.begin())
    --it;
  return static_cast<double>(it->second);

  std::map<std::string, float>::iterator first = Exchange_RPY.begin();
  std::cout << first->first
            << " (earliest date used) for requested date " << Date << std::endl;
  return static_cast<double>(first->second);
}

std::string remove_zeros(std::string num)
{
  size_t dot_pos = num.find('.');
  if (dot_pos == std::string::npos)
    return num;

  size_t last_non_zero = num.find_last_not_of('0');

  if (last_non_zero <= dot_pos)
    return num.substr(0, dot_pos);

  return num.substr(0, last_non_zero + 1);
}

void BitcoinExchange::process_input()
{
  std::string line;

  while (std::getline(infile, line))
  {
    long btc_amount;
    int dot_index = 0;
    try
    {
      line_valid(line);

      std::string date = line.substr(0, 10);
      std::string btc_str = line.substr(13);
      std::string int_part = "";
      std::string fraction = "";
      size_t dot_pos = btc_str.find('.');
      if (dot_pos == std::string::npos)
      {
        btc_amount = strtol(btc_str.c_str(), NULL, 10);
      }
      else
      {
        int_part = btc_str.substr(0, dot_pos);
        fraction = btc_str.substr(dot_pos + 1,FRACTION);
        btc_amount = strtol((int_part + fraction).c_str(), NULL, 10);
      }

      double rate = get_exchangeRate(date);
      long scaled_rate = static_cast<long>(round(rate * 100.0));

      long result = btc_amount * scaled_rate;

      std::ostringstream out;
      out << result;
      std::string result_str = out.str();
      dot_index = result_str.size() - fraction.size() - 2;

      if (dot_index <= 0)
      {
        result_str = std::string(1 - dot_index, '0') + result_str;
        dot_index = 1;
      }
      result_str.insert(dot_index, ".");

      std::cout << date << " => " << btc_str << " = " << remove_zeros(result_str) << std::endl;
    }
    catch (const std::exception &e)
    {
      std::cerr << e.what() << std::endl;
    }
  }
}

int main(int argc, char *argv[])
{
  try
  {
    BitcoinExchange btc;

    btc.validate_input(argc, argv[1]);

    btc.process_input();
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << std::endl;
  }
}
