#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(const std::string& name, Weapon& wp)
  : _name(name), _weapon(wp)
{
  std::cout << "HumanA constructor called" << std::endl;
}

HumanA::~HumanA() {
}

void  HumanA::attack(void) {
  std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}