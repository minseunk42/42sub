#include "Account.hpp"
#include <iostream>
#include <string>

#define DATE "[19920104_091532] "

Account::Account(int initial_deposit)
{
    this->_accountIndex = _nbAccounts++;
    this->_amount = initial_deposit;
    _totalAmount += initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    _displayTimestamp();
    std::cout <<  "index:" << _accountIndex \
    << ";amount:" << _amount \
    << ";created" << std::endl;
}

Account::~Account()
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex \
    << ";amount:" << _amount \
    << ";closed" << std::endl;
}

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts() { return _nbAccounts; }
int	Account::getTotalAmount() { return _totalAmount; }
int	Account::getNbDeposits() { return _totalNbDeposits; }
int	Account::getNbWithdrawals() { return _totalNbWithdrawals; }

void	Account::displayAccountsInfos()
{
    _displayTimestamp();
    std::cout << "accounts:" << Account::getNbAccounts() \
    << ";total:" << Account::getTotalAmount() \
    << ";deposits:" << Account::getNbDeposits() \
    << ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void	Account::makeDeposit( int deposit )
{
     _displayTimestamp();
    std::cout << "index:" << _accountIndex \
    << ";p_amount:" << _amount \
    << ";deposit:" << deposit \
    << ";amount:" << _amount + deposit \
    << ";nb_deposits:" << ++_nbDeposits << std::endl;
    _amount += deposit;
    _totalAmount += deposit;
    _totalNbDeposits += 1;
}
bool	Account::makeWithdrawal( int withdrawal )
{
     _displayTimestamp();
    std::cout <<  "index:" << _accountIndex \
    << ";p_amount:" << _amount;
    if (checkAmount() < withdrawal)
    {
        std::cout << ";withdrawal:refused" << std::endl;
        return 0;
    }
    else
    {
        std::cout << ";withdrawal:" << withdrawal \
        << ";amount:" << _amount - withdrawal \
        << ";nb_withdrawals:" << ++_nbWithdrawals << std::endl;
        _amount -= withdrawal;
        _totalAmount -= withdrawal;
        _totalNbWithdrawals += 1;
    }
    return 1;
}
int		Account::checkAmount( void ) const
{
    return _amount;
}
void	Account::displayStatus( void ) const 
{
     _displayTimestamp();
    std::cout <<  "index:" << _accountIndex \
    << ";amount:" << _amount \
    << ";deposits:" << _nbDeposits \
    << ";withdrawals:" << _nbWithdrawals \
    << std::endl;
}
void	Account::_displayTimestamp( void ) 
{
    std::cout << DATE;
}