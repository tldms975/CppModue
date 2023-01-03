#include "Animal.hpp"
#include <iostream>

Animal::Animal() : _type("Animal") {
  std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal& a) {
  *this = a;
}

Animal& Animal::operator=(const Animal& a) {
  if (this == &a)
    return (*this);
  _type = a._type;
  return (*this);
}

Animal::~Animal() {
  std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(const std::string& type) : _type(type) {
  std::cout << "Animal string constructor called" << std::endl;
}

void  Animal::setType(const std::string &type) {
  _type = type;
}

std::string Animal::getType(void) const {
  return (_type);
}