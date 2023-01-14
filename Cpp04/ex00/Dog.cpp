#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog Default Constructor called\n";
}

Dog::Dog(const Dog& c)
{
	*this = c;
	std::cout << "Dog Copy Constructor called\n";
}

Dog &Dog::operator=(const Dog &c)
{
	if (this == &c)
		return (*this);
	this->type = c.getType();
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog Destructor called\n";
}

void Dog::makeSound() const
{
	std::cout << "~Wang Wang~\n";
}
