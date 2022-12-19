#include "Account.hpp"
#include <iostream>
#include <ctime>

Account::Account()
{
}

Account::Account(int initial_deposit)
{
	_displayTimestamp();
	_accountIndex = _nbAccounts++;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbDeposits = 0;
	_totalAmount += initial_deposit;
	std::cout << "index:" << _accountIndex << ';';
	std::cout << "amount:" << _amount << ';';
	std::cout << "created\n";
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ';';
	std::cout << "amount:" << _amount << ';';
	std::cout << "closed\n";
	_totalAmount -= _amount;
	_nbAccounts--;
}

int	Account::getNbAccounts()
{
	return (_nbAccounts);
}

int	Account::getTotalAmount()
{
	return (_totalAmount);
}

int	Account::getNbDeposits()
{
	return (_nbDeposits);
}

int	Account::getNbWithdrawals()
{
	return (_nbWithdrawals);
}

void	Account::makeDeposit(int deposit)
{

}

bool	Account::makeWithdrawal( int withdrawal )
{

}

int		Account::checkAmount() const
{

}

void	Account::displayStatus() const
{

}

void	Account::displayAccountsInfos()
{
	std::cout << "accounts:" << getNbAccounts() << ';';
	std::cout << "total:" << getTotalAmount() << ';';
	std::cout << "deposits:" << getNbDeposits() << ';';
	std::cout << "withdrawals:" << getNbWithdrawals() << '\n';
}

void Account::_displayTimestamp()
{
	const time_t	timeStamp = time(NULL);
	char	buf[16];

	strftime(buf, sizeof(buf), "%Y%m%d_%H%M%S", localtime(&timeStamp));
}
