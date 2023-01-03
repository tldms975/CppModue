#include "ClapTrap.hpp"
#include <iostream>

int main(void) {
  ClapTrap  a("hena");
  ClapTrap  b("jasong");

  a.attack(b.getName());
  b.takeDamage(a.getDamage());
  b.getArmed();
  for (int i = 0; i < 4; i++) {
    b.attack(a.getName());
    a.takeDamage(b.getDamage());
  }
  a.beRepaired(1);
  for (int i = 0; i < 7; i++) {
    b.attack(a.getName());
    a.takeDamage(b.getDamage());
  }
  return (0);
}