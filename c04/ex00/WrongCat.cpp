#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& wc) {
  *this = wc;
}

WrongCat& WrongCat::operator=(const WrongCat& wc) {
  if (this == &wc)
    return (*this);
  _type = wc._type;
  return (*this);
}

WrongCat::~WrongCat() {
  std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat::WrongCat(const std::string& type) : WrongAnimal(type) {
  std::cout << "WrongCat string constructor called" << std::endl;
}

std::string	WrongCat::getType(void) const {
  return (_type);
}

void  WrongCat::setType(const std::string& type) {
  _type = type;
}

void  WrongCat::makeSound(void) const {
  std::cout << "This is WrongCat's makesound but it will not opreate" << std::endl;
}