#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(void) : ClapTrap()
{
  std::cout << "Default FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name, 100, 100, 30)
{
  std::cout << "FragTrap constructor with name called" << std::endl;
}

FragTrap::FragTrap(const std::string& name,
                    const int& health,
                    const int& energy,
                    const int& damage
                  ) : ClapTrap(name, health, energy, damage)
{
  std::cout << "FragTrap constructor with full info called" << std::endl;
  std::cout << this->_health << std::endl;
}

FragTrap::FragTrap(const FragTrap& f) {
  *this = f;
}


FragTrap& FragTrap::operator=(const FragTrap& f) {
  if (this == &f)
    return (*this);
  _name = f._name;
  _health = f._health;
  _energy = f._energy;
  _damage = f._damage;
  return (*this);
}

FragTrap::~FragTrap(void) {
  std::cout << "FragTrap " << "<" << _name << ">" << " destructor called" << std::endl;
}

void  FragTrap::attack(const std::string& target) {
  if (this->_health > 0) {
    if (this->_energy > 0) {
      std::cout << "FragTrap " << "<" << _name << ">" << " attacks " << target << ", causing " << _damage << " points of damage!";
      this->_energy -= 1;
      std::cout << " - " << "<" << _name << ">" << " Remain Energy : " << _energy << std::endl;
    }
    else
      std::cout << "FragTrap " << "<" << _name << ">" << " is out of energy" << std::endl;
  }
  else
    std::cout << "FragTrap " << "<" << _name << ">" << " is already dead" << std::endl;
}

void  FragTrap::takeDamage(unsigned int amount) {
  if (this->_health > 0) {
    this->_health -= amount;
    std::cout << "FragTrap " << "<" << _name << ">" << " takes " << amount << " points of damage!";
    std::cout << " - " << "<" << _name << ">" << " Remain Health : " << _health << std::endl;
    if (_health < 0)
      std::cout << "FragTrap " << "<" << _name << ">" << " is killed" << std::endl;
  }
  else
    std::cout << "FragTrap " << "<" << _name << ">" << " is already dead" << std::endl;
}

void  FragTrap::beRepaired(unsigned int amount) {
  if (this->_health > 0) {
    if (this->_energy > 0) {
      std::cout << "FragTrap " << "<" << _name << ">" << " repaired " << amount << " points" << std::endl;
      _health += amount;
      _energy -= 1;
    }
    else
      std::cout << "FragTrap " << "<" << _name << ">" << " have not enough energy" << std::endl;
  }
  else
    std::cout << "FragTrap " << "<" << _name << ">" << " already dead" << std::endl;
}

void  FragTrap::highFivesGuys(void) {
  std::cout << "Hurrrray! HighFive!! >_<" << std::endl;
}