#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(void) : _value(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed& f)
{
	std::cout << "Copy constructor called\n";
	*this = f;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called\n";
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return (this->_value);
}

void Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

Fixed& Fixed::operator=(const Fixed& f)
{
	std::cout << "Copy assignment operator called\n";
	this->_value = f.getRawBits();
	return (*this);
}
