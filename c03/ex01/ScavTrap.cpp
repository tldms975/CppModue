#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(void) : ClapTrap(), _guard_flag(false)
{
  std::cout << "Default ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name, 100, 50, 20), _guard_flag(false)
{
  std::cout << "ScavTrap constructor with name called" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name,
                    const int& health,
                    const int& energy,
                    const int& damage
                  ) : ClapTrap(name, health, energy, damage), _guard_flag(false)
{
  std::cout << "ScavTrap constructor with full info called" << std::endl;
  std::cout << this->_health << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& s) {
  *this = s;
}


ScavTrap& ScavTrap::operator=(const ScavTrap& s) {
  if (this == &s)
    return (*this);
  _name = s._name;
  _health = s._health;
  _energy = s._energy;
  _damage = s._damage;
  return (*this);
}

ScavTrap::~ScavTrap(void) {
  std::cout << "ScavTrap " << "<" << _name << ">" << " destructor called" << std::endl;
}

void  ScavTrap::guardGate(void) {
  _guard_flag = true;
  std::cout << "You cannot pass away" << std::endl;
}

void  ScavTrap::attack(const std::string& target) {
  if (this->_health > 0) {
    if (this->_energy > 0) {
      std::cout << "ScavTrap " << "<" << _name << ">" << " attacks " << target << ", causing " << _damage << " points of damage!";
      this->_energy -= 1;
      std::cout << " - " << "<" << _name << ">" << " Remain Energy : " << _energy << std::endl;
    }
    else
      std::cout << "ScavTrap " << "<" << _name << ">" << " is out of energy" << std::endl;
  }
  else
    std::cout << "ScavTrap " << "<" << _name << ">" << " is already dead" << std::endl;
}

void  ScavTrap::takeDamage(unsigned int amount) {
  if (this->_health > 0) {
    this->_health -= amount;
    std::cout << "ScavTrap " << "<" << _name << ">" << " takes " << amount << " points of damage!";
    std::cout << " - " << "<" << _name << ">" << " Remain Health : " << _health << std::endl;
    if (_health < 0)
      std::cout << "ScavTrap " << "<" << _name << ">" << " is killed" << std::endl;
  }
  else
    std::cout << "ScavTrap " << "<" << _name << ">" << " is already dead" << std::endl;
}

void  ScavTrap::beRepaired(unsigned int amount) {
  if (this->_health > 0) {
    if (this->_energy > 0) {
      std::cout << "ScavTrap " << "<" << _name << ">" << " repaired " << amount << " points" << std::endl;
      _health += amount;
      _energy -= 1;
    }
    else
      std::cout << "ScavTrap " << "<" << _name << ">" << " have not enough energy" << std::endl;
  }
  else
    std::cout << "ScavTrap " << "<" << _name << ">" << " already dead" << std::endl;
}