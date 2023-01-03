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

Fixed::~Fixed(void)
{
	std::cout << "Destructor called\n";
}

float Fixed::toFloat(void) const
{
	return ((float)this->_value / (float)(1 << this->_fractionalBits));
}

int Fixed::toInt(void) const
{
	return (this->_value >> this->_fractionalBits);
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
	this->_value = f.getRawBits();
	return (*this);
}

bool Fixed::operator<(const Fixed& f) const
{
	return (this->_value < f._value);
}

bool Fixed::operator>(const Fixed& f) const
{
	return (this->_value > f._value);
}

bool Fixed::operator>=(const Fixed& f) const
{
	return (this->_value >= f._value);
}

bool Fixed::operator<=(const Fixed& f) const
{
	return (this->_value <= f._value);
}

bool Fixed::operator==(const Fixed& f) const
{
	return (this->_value == f._value);
}

bool Fixed::operator!=(const Fixed& f) const
{
	return (this->_value != f._value);
}

Fixed Fixed::operator+(const Fixed& f) const
{
	Fixed res;

	res.setRawBits(this->_value + f.getRawBits());
	return (res);
}

Fixed Fixed::operator-(const Fixed& f) const
{
	Fixed res;

	res.setRawBits(this->_value - f.getRawBits());
	return (res);
}

Fixed Fixed::operator*(const Fixed& f) const
{
	Fixed res;

	res.setRawBits((this->_value * f.getRawBits()) >> this->_fractionalBits);
	return (res);
}

Fixed Fixed::operator/(const Fixed& f) const
{
	Fixed res;

	res.setRawBits((this->_value << this->_fractionalBits) / f.getRawBits());
	return (res);
}

Fixed& Fixed::operator++(void)
{
	this->_value++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed res(*this);

	this->_value++;
	return (res);
}

Fixed& Fixed::operator--(void)
{
	this->_value--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed res(*this);

	this->_value--;
	return (res);
}

Fixed& Fixed::min(Fixed& f1, Fixed& f2)
{
	return (f1 < f2 ? f1 : f2);
}

const Fixed& Fixed::min(const Fixed& f1, const Fixed& f2)
{
	return (f1 < f2 ? f1 : f2);
}

Fixed& Fixed::max(Fixed& f1, Fixed& f2)
{
	return (f1 > f2 ? f1 : f2);
}

const Fixed& Fixed::max(const Fixed& f1, const Fixed& f2)
{
	return (f1 > f2 ? f1 : f2);
}

std::ostream& operator<<(std::ostream& os, const Fixed& f)
{
	os << f.toFloat();
	return (os);
}
