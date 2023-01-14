#include "Animal.hpp"
#include <iostream>

Animal::Animal()
{
	this->type = "";
	std::cout << "Animal Default Constructor called\n";
}

Animal::Animal(const std::string type)
{
	this->type = type;
	std::cout << "Animal "<< this->type << " Constructor called\n";
}

Animal::~Animal()
{
	std::cout << "Animal "<< this->type << " Destructor called\n";
}

Animal &Animal::operator=(const Animal &c)
{
	if (this == &c)
		return (*this);
	this->type = c.getType();
	return (*this);
}

Animal::Animal(const Animal &c)
{
	this->type = c.type;
	std::cout << "Animal "<< this->type << " Copy Constructor called\n";
}

std::string Animal::getType() const
{
	return (this->type);
}

void Animal::makeSound() const
{
	std::cout << "~Animalllllll~\n";
}
