#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat Default Constructor called\n";
}

WrongCat::WrongCat(const WrongCat& c)
{
	*this = c;
	std::cout << "WrongCat Copy Constructor called\n";
}

WrongCat &WrongCat::operator=(const WrongCat &c)
{
	if (this == &c)
		return (*this);
	this->type = c.getType();
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destructor called\n";
}