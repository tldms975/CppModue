#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon(std::string type)
{
	this->setType(type);
}

Weapon::~Weapon()
{
}

void	Weapon::setType(std::string type)
{
	this->type = type;
}

std::string	Weapon::getType() const
{
	return (this->type);
}
