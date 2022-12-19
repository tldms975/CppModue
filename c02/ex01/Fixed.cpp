#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(void) : _f_point_val(0){
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int i) : _f_point_val(i << Fixed::_frac_bits) {
  std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float f) : _f_point_val(roundf(f * (1 << Fixed::_frac_bits))) {
  std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed(void) {
  std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& f) {
  std::cout << "Copy constructor called" << std::endl;
  *this = f;
}

Fixed& Fixed::operator=(const Fixed& f) { 
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &f)
    _f_point_val = f.getRawbits();
  return (*this);
}

int   Fixed::getRawbits(void) const {
  return (_f_point_val);
}

void  Fixed::setRawbits(int const raw) {
  _f_point_val = raw;
}

int Fixed::toInt(void) const {
  return (_f_point_val >> _frac_bits);
}

float Fixed::toFloat(void) const {
  return (float(_f_point_val) / (1 << 8));
}

std::ostream& operator<<(std::ostream&, const Fixed& f) {
  return (std::cout << f.toFloat());
}