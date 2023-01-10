#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(void)
{
	std::cout << "Default FragTrap Constructor called\n";
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap " << this->_name << " created\n";
}

FragTrap::FragTrap(const FragTrap& c) : ClapTrap(c)
{
	std::cout << "FragTrap " << this->_name << " copy constructor called\n";
}

FragTrap& FragTrap::operator=(const FragTrap& c)
{
	if (this == &c)
		return (*this);
	ClapTrap::operator=(c);
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->_name << " destroyed\n";
}

void	FragTrap::highFivesGuys(void)
{
	if (this->_hitPoints <= 0 || this->_energyPoints <= 0)
		std::cout << "FragTrap " << this->_name << " can't do anything.\n";
	else
		std::cout << "FragTrap " << this->_name << " has entered in High five guys mode\n";
}

void	FragTrap::attack(std::string const& target)
{
	if (this->_hitPoints > 0 && this->_energyPoints > 0)
	{
		std::cout << "FragTrap " << this->_name << " attacks " << target << \
		", causing " << this->_attackDamage << " points of damage!\n";
		this->_energyPoints -= 1;
	}
	else
		std::cout << "FragTrap " << this->_name << " can't do anything.\n";
}

void	FragTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints > 0)
	{
		std::cout << "FragTrap " << this->_name << " takes " << amount << \
		" points of damage!\n";
		this->_hitPoints -= amount;
	}
	else
		std::cout << "FragTrap " << this->_name << " can't do anything.\n";
}

void	FragTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints <= 0 || this->_energyPoints <= 0)
	{
		std::cout << "FragTrap " << this->_name << " gained " << amount << \
		" points!\n";
		this->_hitPoints += amount;
	}
	else
		std::cout << "FragTrap " << this->_name << " can't do anything.\n";
}
