/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:07:11 by octoross          #+#    #+#             */
/*   Updated: 2025/03/05 19:14:27 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
    _totalAmount += initial_deposit;
    _accountIndex = _nbAccounts;
    _nbAccounts ++;
    _amount = initial_deposit; 
    _nbDeposits = 0;
    _nbWithdrawals = 0;

    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "created" << std::endl;
}

void    Account::_displayTimestamp(void)
{
    time_t      timestamp = time(0);
    tm*    time_data = localtime(&timestamp);

    std::cout << "[" << time_data->tm_year +  1900;
    std::cout << std::setfill('0') << std::setw(2) << time_data->tm_mon + 1;
    std::cout << std::setw(2) << time_data->tm_mday << "_";
    std::cout << std::setw(2) << time_data->tm_hour;
    std::cout << std::setw(2) << time_data->tm_min;
    std::cout << std::setw(2) << time_data->tm_sec << "]";
}

Account::Account(void) {}

Account::~Account(void)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "closed" << std::endl;
}

int Account::getNbAccounts(void) { return _nbAccounts; }
int	Account::getTotalAmount(void) { return _totalAmount; }
int Account::getNbDeposits(void) { return _totalNbDeposits; }
int Account::getNbWithdrawals(void) { return _totalNbWithdrawals; }

void    Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts << ";";
    std::cout << "total:" << _totalAmount << ";";
    std::cout << "deposits:" << _totalNbDeposits << ";";
    std::cout << "withdrawals:" << _totalNbWithdrawals << std::endl;
}

void	Account::makeDeposit(int deposit)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "p_amount:" << _amount << ";";
    std::cout << "deposit:" << deposit << ";";
    _amount += deposit;
    std::cout << "amount:" << _amount << ";";
    _nbDeposits ++;
    std::cout << "nb_deposits:" << _nbDeposits << std::endl;

    _totalAmount += deposit;
    _totalNbDeposits ++;
}

bool	Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "p_amount:" << _amount << ";";
    if (withdrawal <= _amount)
    {   
        std::cout << "withdrawal:" << withdrawal << ";";
        _amount -= withdrawal;
        std::cout << "amount:" << _amount << ";";
        _nbWithdrawals ++;
        std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;
        _totalAmount -= withdrawal;
        _totalNbWithdrawals ++;
        return (true);
    }
    std::cout << "withdrawal:refused" << std::endl;
    return (false);
}

int		Account::checkAmount(void) const
{
    return (_amount);
}


void	Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "deposits:" << _nbDeposits << ";";
    std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}