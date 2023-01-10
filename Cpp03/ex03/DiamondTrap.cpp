#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(void)
{
	std::cout << "DiamondTrap default constructor called\n";
}

DiamondTrap::DiamondTrap(std::string name)
{
	ClapTrap::_name = name + "_clap_name";
	this->_name = name;
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap " << this->_name <<" created\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap &c)
{
	*this = c;
	std::cout << "DiamondTrap " << this->_name << " copy constructor called\n";
}


DiamondTrap& DiamondTrap::operator=(const DiamondTrap &c)
{
	if (this == &c)
		return (*this);
	this->_name			= c._name;
	this->_attackDamage = c._attackDamage;
	this->_energyPoints = c._energyPoints;
	this->_hitPoints	= c._hitPoints;
	return (*this);
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap " << this->_name <<" destroyed\n";
}


void	DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap's name is " << this->_name << std::endl;
	std::cout << "ClapTrap's name is " << this->ClapTrap::_name << std::endl;
}

void	DiamondTrap::attack(std::string const& target)
{
	ScavTrap::attack(target);
}
