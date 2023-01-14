#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat Default Constructor called\n";
}

Cat::Cat(const Cat& c)
{
	*this = c;
	std::cout << "Cat Copy Constructor called\n";
}

Cat &Cat::operator=(const Cat &c)
{
	if (this == &c)
		return (*this);
	this->type = c.getType();
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat Destructor called\n";
}

void Cat::makeSound() const
{
	std::cout << "~Meowwww~\n";
}