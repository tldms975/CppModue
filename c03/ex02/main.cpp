#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main(void) {
  ClapTrap a("alee");
  ScavTrap b("giykim");
  FragTrap c("yjo");

  a.attack(b.getName());
  b.takeDamage(a.getDamage());
  for (int i = 0; i < 4; i++) {
    b.attack(a.getName());
    a.takeDamage(b.getDamage());
  }
  a.beRepaired(1);
  for (int i = 0; i < 7; i++) {
    c.attack(a.getName());
    a.takeDamage(c.getDamage());
    c.attack(b.getName());
    b.takeDamage(c.getDamage());
    b.attack("test target");
  }
  b.guardGate();
  c.highFivesGuys();
  return (0);
}