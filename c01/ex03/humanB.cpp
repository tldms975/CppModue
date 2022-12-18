#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(const std::string &name)
  : _name(name), _weapon(NULL)
{
  std::cout << "HumanB constructor called" << std::endl;
}

HumanB::~HumanB() {}

void  HumanB::setWeapon(Weapon &wp) {
  this->_weapon = &wp;
}

void  HumanB::attack(void) {
  if (!this->_weapon)
    std::cout << this->_name << " attacks with their empty type" << std::endl;
  else
    std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}