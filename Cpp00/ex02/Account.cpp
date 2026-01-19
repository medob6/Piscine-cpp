/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 14:07:41 by mbousset          #+#    #+#             */
/*   Updated: 2025/10/15 18:43:20 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
        : _accountIndex(_nbAccounts), _amount(initial_deposit),
      _nbDeposits(0), _nbWithdrawals(0)
{
    _nbAccounts++;
    _totalAmount += initial_deposit;

    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";amount:" << _amount
              << ";created" << std::endl;
}

Account::~Account(void)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" 
              << _amount << ";closed" << std::endl;
}

void	Account::_displayTimestamp( void )
{
    std::time_t now = time(NULL);
    std::tm *ptm = std::localtime(&now);
    char buf[20];
    std::strftime(buf, sizeof(buf), "%Y%m%d_%H%M%S", ptm);
    std::cout << "[" << buf << "] ";
}
int Account::getNbAccounts(void) { return (_nbAccounts);}
int Account::getTotalAmount(void) { return (_totalAmount);}
int Account::getNbDeposits(void) { return (_totalNbDeposits);}
int Account::getNbWithdrawals(void) { return (_totalNbWithdrawals);}

void Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:"
              << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit)
{
    _displayTimestamp();

    std::cout << "index:" << _accountIndex
              << ";p_amount:" << _amount
              << ";deposit:" << deposit;
    _amount += deposit;             
    _totalAmount += deposit; 
    _nbDeposits++;                 
    _totalNbDeposits++;            

    std::cout << ";amount:" << _amount
              << ";nb_deposits:" << _nbDeposits
              << std::endl;
}

 bool	Account::makeWithdrawal(int withdrawal)
 {
     _displayTimestamp();
     if (withdrawal > _amount)
     {
         std::cout << "index:" << _accountIndex
                   << ";p_amount:" << _amount<<";withdrawal:refused\n";
         return (false);
     }
    std::cout << "index:" << _accountIndex
        << ";p_amount:" << _amount
        << ";withdrawal:" << withdrawal;
    _amount -= withdrawal;             
    _totalAmount -= withdrawal;
    _nbWithdrawals++;
    _totalNbWithdrawals++;
    std::cout << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals  << std::endl;
    return (true);
 }

 int	Account::checkAmount() const
 {
     return (_amount);
 }

void	Account::displayStatus( void ) const
{
     _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount 
              << ";deposits:" << _nbDeposits << ";withdrawals:" 
              << _nbWithdrawals  << std::endl;
}


// int main()
// {
//     Account acc1(1000);
//     Account acc2(500);
//     Account acc3(200);

//     Account::displayAccountsInfos();

//     acc1.makeDeposit(200);
//     acc2.makeDeposit(100);
//     acc3.makeDeposit(50);
    
//     acc1.makeWithdrawal(500);
//     acc2.makeWithdrawal(700);
//     acc3.makeWithdrawal(100);


//     acc1.displayStatus();
//     acc2.displayStatus();
//     acc3.displayStatus();


//     Account::displayAccountsInfos();

//     return 0;
// }
