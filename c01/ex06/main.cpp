#include <iostream>
#include "Harl.hpp"

int main(int ac, char *av[]) {
  Harl  h;

  if (ac != 3) {
    std::cerr << "There must be only one argument" << std::endl;
    return (1);
  }
}