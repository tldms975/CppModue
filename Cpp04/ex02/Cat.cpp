#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal("Cat"), _brain(new Brain())
{
	std::cout << "Cat Default Constructor called\n";
}

Cat::Cat(const Cat& c) : Animal(c)
{
	this->_brain = new Brain();
	std::cout << "Cat Copy Constructor called\n";
}

Cat &Cat::operator=(const Cat &c)
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

Cat::~Cat()
{
	if (this->_brain != NULL)
		delete this->_brain;
	std::cout << "Cat Destructor called\n";
}

void Cat::makeSound() const
{
	std::cout << "~Meowwww~\n";
}

Brain *Cat::getBrain() const
{
	return (this->_brain);
}