#include "Account.hpp"

Account::Account(int initial_deposit)
{

}

Account::~Account()
{

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

}

void	Account::makeDeposit( int deposit ){}
bool	Account::makeWithdrawal( int withdrawal ){return 0;}
int		Account::checkAmount( void ) const{return 0;}
void	Account::displayStatus( void ) const {}
void	Account::_displayTimestamp( void ) {}