#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(void) : _name("Default"), _health(10), _energy(10), _damage(0) 
{
  std::cout << "Default ClapTrap Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : _name(name), _health(10), _energy(10), _damage(0)
{
  std::cout << "ClapTrap " << "<" << _name << ">" << " with name Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name,
                    const int& health,
                    const int& energy,
                    const int& damage)
                    : _name(name), _health(health), _energy(energy), _damage(damage)
{
  std::cout << "ClapTrap " << "<" << _name << ">" << " with full info Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& c) {
  *this = c;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& c) {
  if (this == &c)
    return (*this);
  _name = c.getName();
  _health = c.getHealth();
  _energy = c.getEnergy();
  _damage = c.getDamage();
  return (*this);
}

ClapTrap::~ClapTrap(void) {
  std::cout << "ClapTrap " << "<" << _name << ">" << " destructor called" << std::endl;
}

std::string ClapTrap::getName(void) const {
  return (this->_name);
}

long long ClapTrap::getHealth(void) const {
  return (this->_health);
}

long long ClapTrap::getEnergy(void) const {
  return (this->_energy);
}

long long ClapTrap::getDamage(void) const {
  return (this->_damage);
}

void      ClapTrap::getArmed(void) {
  std::cout << "ClapTrap " << "<" << _name << ">" << " has armed!" << std::endl;
  _damage = 2;
}

void  ClapTrap::attack(const std::string& target) {
  if (this->_health > 0) {
    if (this->_energy > 0) {
      std::cout << "ClapTrap " << "<" << _name << ">" << " attacks " << target << ", causing " << _damage << " points of damage!";
      this->_energy -= 1;
      std::cout << " - " << "<" << _name << ">" << " Remain Energy : " << _energy << std::endl;
    }
    else
      std::cout << "ClapTrap " << "<" << _name << ">" << " is out of energy" << std::endl;
  }
  else
    std::cout << "ClapTrap " << "<" << _name << ">" << " is already dead" << std::endl;
}

void  ClapTrap::takeDamage(unsigned int amount) {
  if (this->_health > 0) {
    this->_health -= amount;
    std::cout << "ClapTrap " << "<" << _name << ">" << " takes " << amount << " points of damage!";
    std::cout << " - " << "<" << _name << ">" << " Remain Health : " << _health << std::endl;
    if (_health < 0)
      std::cout << "ClapTrap " << "<" << _name << ">" << " is killed" << std::endl;
  }
  else
    std::cout << "ClapTrap " << "<" << _name << ">" << " is already dead" << std::endl;
}

void  ClapTrap::beRepaired(unsigned int amount) {
  if (this->_health > 0) {
    if (this->_energy > 0) {
      std::cout << "ClapTrap " << "<" << _name << ">" << " repaired " << amount << " points" << std::endl;
      _health += amount;
      _energy -= 1;
    }
    else
      std::cout << "ClapTrap " << "<" << _name << ">" << " have not enough energy" << std::endl;
  }
  else
    std::cout << "ClapTrap " << "<" << _name << ">" << " already dead" << std::endl;
}