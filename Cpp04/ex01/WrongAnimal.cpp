#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal()
{
	this->type = "";
	std::cout << "WrongAnimal Default Constructor called\n";
}

WrongAnimal::WrongAnimal(const std::string type)
{
	this->type = type;
	std::cout << "WrongAnimal "<< this->type << " Constructor called\n";
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal "<< this->type << " Destructor called\n";
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &c)
{
	if (this == &c)
		return (*this);
	this->type = c.getType();
	return (*this);
}

WrongAnimal::WrongAnimal(const WrongAnimal &c)
{
	*this = c;
	std::cout << "WrongAnimal "<< this->type << "Copy Constructor called\n";
}

std::string WrongAnimal::getType() const
{
	return (this->type);
}

void WrongAnimal::makeSound() const
{
	std::cout << "~WrongAnimalllllll~\n";
}
