#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie()
{
	this->_name = "";
}

Zombie::Zombie(std::string name)
{
	this->_name = name;
	std::cout << this->_name << "\n";
}

Zombie::~Zombie()
{
	std::cout << "~" << this->_name << "\n";
}

void	Zombie::announce()
{
	std::cout << this->_name << ": BraiiiiiinnnzzzZ...\n";
}

void	Zombie::setName(std::string name)
{
	this->_name = name;
}
