#include "Fixed.hpp"
#include <iostream>
#include <cmath>

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

Fixed& Fixed::operator=(const Fixed& f)
{
	this->_value = f.getRawBits();
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const Fixed& f)
{
	os << f.toFloat();
	return (os);
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called\n";
	this->_value = value << this->_fractionalBits;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called\n";
	this->_value = roundf(value * (1 << this->_fractionalBits));
}

float Fixed::toFloat(void) const
{
	return ((float)this->_value / (float)(1 << this->_fractionalBits));
}

int Fixed::toInt(void) const
{
	return (this->_value >> this->_fractionalBits);
}
