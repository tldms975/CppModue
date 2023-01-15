#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal("Dog"), _brain(new Brain())
{
	std::cout << "Dog Default Constructor called\n";
}

Dog::Dog(const Dog& c) : Animal(c)
{
	this->_brain = new Brain();
	std::cout << "Dog Copy Constructor called\n";
}

Dog &Dog::operator=(const Dog &c)
{
	if (this == &c)
		return (*this);
	if (this->_brain != NULL)
	{
		delete this->_brain;
		this->_brain = NULL;
	}
	this->_brain = new Brain();
	this->type = c.getType();
	return (*this);
}

Dog::~Dog()
{
	if (this->_brain != NULL)
		delete this->_brain;
	std::cout << "Dog Destructor called\n";
}

void Dog::makeSound() const
{
	std::cout << "~Wang Wang~\n";
}

Brain *Dog::getBrain() const
{
	return (this->_brain);
}
