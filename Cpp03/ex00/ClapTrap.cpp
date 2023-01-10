#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(void)
{
	this->_name = "???";
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
	std::cout << "Default Constructor called\n";
}

ClapTrap::ClapTrap(std::string name)
{
	this->_name = name;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
	std::cout << "ClapTrap " << this->_name << " created\n";
}

ClapTrap::ClapTrap(const ClapTrap& c)
{
	std::cout << "ClapTrap " << this->_name << " Constructor called\n\n";
	*this = c;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& c)
{
	if (this == &c)
		return (*this);
	this->_name = c._name;
	this->_hitPoints = c._hitPoints;
	this->_energyPoints = c._energyPoints;
	this->_attackDamage = c._attackDamage;
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap " << this->_name << " destroyed\n";
}

void	ClapTrap::attack(std::string const& target)
{
	if (this->_hitPoints > 0 && this->_energyPoints > 0)
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target << \
		", causing " << this->_attackDamage << " points of damage!\n";
		this->_energyPoints -= 1;
	}
	else
		std::cout << "ClapTrap " << this->_name << " can't do anything.\n";
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints > 0)
	{
		std::cout << "ClapTrap " << this->_name << " takes " << amount << \
		" points of damage!\n";
		this->_hitPoints -= amount;
	}
	else
		std::cout << "ClapTrap " << this->_name << " can't do anything.\n";
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints <= 0 || this->_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " gained " << amount << \
		" points!\n";
		this->_hitPoints += amount;
	}
	else
		std::cout << "ClapTrap " << this->_name << " can't do anything.\n";
}

void	ClapTrap::printStatus(void)
{
	std::cout <<"\nInfo <" << this->_name << ">\nhitPoint: " << this->_hitPoints << \
	"\nenergyPoint: " << this->_energyPoints << "\nattackDamage: " << this->_attackDamage << "\n\n";
}