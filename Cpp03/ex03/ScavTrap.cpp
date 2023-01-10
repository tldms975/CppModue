#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap()
{
	std::cout << "Default ScavTrap constructor called\n";
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap " << this->_name << " created\n";
}

ScavTrap::ScavTrap(const ScavTrap& c) : ClapTrap(c)
{
	std::cout << "ScavTrap " << this->_name << "copy constructor called\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap& c)
{
	if (this == &c)
		return (*this);//
	ClapTrap::operator=(c);
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->_name << " destroyed\n";
}

void	ScavTrap::guardGate(void)
{
	if (this->_hitPoints <= 0 || this->_energyPoints <= 0)
		std::cout << "ScavTrap " << this->_name << " can't do anything.\n";
	else
		std::cout << "ScavTrap " << this->_name << " has entered in Gate keeper mode\n";
}

void	ScavTrap::attack(std::string const& target)
{
	if (this->_hitPoints > 0 && this->_energyPoints > 0)
	{
		std::cout << "ScavTrap " << this->_name << " attacks " << target << \
		", causing " << this->_attackDamage << " points of damage!\n";
		this->_energyPoints -= 1;
	}
	else
		std::cout << "ScavTrap " << this->_name << " can't do anything.\n";
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints > 0)
	{
		std::cout << "ScavTrap " << this->_name << " takes " << amount << \
		" points of damage!\n";
		this->_hitPoints -= amount;
	}
	else
		std::cout << "ScavTrap " << this->_name << " can't do anything.\n";
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints <= 0 || this->_energyPoints <= 0)
	{
		std::cout << "ScavTrap " << this->_name << " gained " << amount << \
		" points!\n";
		this->_hitPoints += amount;
	}
	else
		std::cout << "ScavTrap " << this->_name << " can't do anything.\n";
}