#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon(void)
{
  std::cout << "Weapon constructor 1 called" << std::endl;
}

Weapon::Weapon(std::string type) {
  this->setType(type);
  std::cout << "Weapon constructor called" << std::endl;
}

Weapon::~Weapon(void) {
  std::cout << "Weapon destructor callled" << std::endl;
}

const std::string& Weapon::getType(void) const{
  return (this->_type);
}

void  Weapon::setType(const std::string &type) {
  this->_type = type;
}