#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(void): _f_point_val(0){
  // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int i): _f_point_val(i << Fixed::_frac_bits) {
  // std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float f): _f_point_val(roundf(f * (1 << Fixed::_frac_bits))) {
  // std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed(void) {
  // std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& f) {
  // std::cout << "Copy constructor called" << std::endl;
  *this = f;
}

Fixed& Fixed::operator=(const Fixed& f) { 
  // std::cout << "Copy assignment operator called" << std::endl;
  if (this == &f)
    return (*this);
  _f_point_val = f.getRawbits();
  return (*this);
}

bool  Fixed::operator<(const Fixed& f) const {
  return (this->_f_point_val < f._f_point_val);
}

bool  Fixed::operator>(const Fixed& f) const {
  return (this->_f_point_val > f._f_point_val);
}

bool  Fixed::operator>=(const Fixed& f) const {
  return (this->_f_point_val >= f._f_point_val);
}

bool  Fixed::operator<=(const Fixed& f) const {
  return (this->_f_point_val <= f._f_point_val);
}

bool  Fixed::operator==(const Fixed& f) const {
  return (this->_f_point_val == f._f_point_val);
}

bool  Fixed::operator!=(const Fixed& f) const {
  return (this->_f_point_val != f._f_point_val);
}

Fixed Fixed::operator+(const Fixed &f) const {
  Fixed res;

  res.setRawbits(this->getRawbits() + f.getRawbits());
  return (res);
}

Fixed Fixed::operator-(const Fixed &f) const {
  Fixed res;

  res.setRawbits(this->getRawbits() - f.getRawbits());
  return (res);
}

Fixed Fixed::operator*(const Fixed &f) const {
  return (Fixed(this->toFloat() * f.toFloat()));
}

Fixed Fixed::operator/(const Fixed &f) const {

  return (Fixed(this->toFloat() / f.toFloat()));
}

Fixed&  Fixed::operator++(void) {
  this->_f_point_val++;
  return (*this);  
} 

Fixed   Fixed::operator++(int) {
  Fixed temp(*this);

  this->_f_point_val++;
  return (temp);
} // post-increment

Fixed&  Fixed::operator--(void) {
  this->_f_point_val--;
  return (*this);  
} // pre-decrement

Fixed   Fixed::operator--(int) {
  Fixed temp(*this);

  this->_f_point_val--;
  return (temp);
} // post-decrements

int   Fixed::getRawbits(void) const {
  return (_f_point_val);
}

void  Fixed::setRawbits(int const raw) {
  _f_point_val = raw;
}

int   Fixed::toInt(void) const {
  return (_f_point_val >> _frac_bits);
}

float Fixed::toFloat(void) const {
  return (float(_f_point_val) / (1 << 8));
}

Fixed& Fixed::min(Fixed& f1, Fixed& f2) {
  if (f1 > f2)
    return (f2);
  return (f1);
}

const Fixed& Fixed::min(const Fixed& f1, const Fixed& f2) {
  if (f1 > f2)
    return (f2);
  return (f1);
}

Fixed& Fixed::max(Fixed& f1, Fixed& f2) {
  if (f1 < f2)
    return (f2);
  return (f1);
}

const Fixed& Fixed::max(const Fixed &f1, const Fixed& f2) {
  if (f1 < f2)
    return (f2);
  return (f1);
}

std::ostream& operator<<(std::ostream&, const Fixed& f) {
  return (std::cout << f.toFloat());
}