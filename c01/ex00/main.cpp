#include "Zombie.hpp"
#include <iostream>

int main(void) {
  Zombie stack("stack");

  stack.announce();
  randomChump("heap");
  return (0);
}