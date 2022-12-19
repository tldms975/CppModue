#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(void) : _f_point_val(0){
  std::cout << "Fixed constructor called" << std::endl;
}

Fixed::~Fixed(void) {
  std::cout << "Fixed destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& f) {
  std::cout << "Fixed copy constructor called" << std::endl;
  *this = f;
}

Fixed& Fixed::operator=(const Fixed& f) {
  std::cout << "Fixed copy assignment operator overload function called" << std::endl;
  if (this == &f)
    return (*this);
  _f_point_val = f.getRawbits();
  return (*this);
}

int   Fixed::getRawbits(void) const {
  std::cout << "getRawbits member function called" << std::endl;
  return (_f_point_val);
}

void  Fixed::setRawbits(int const raw) {
  std::cout << "setRawbits member function called" << std::endl;
  _f_point_val = raw;
}