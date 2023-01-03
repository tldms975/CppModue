#include "Brain.hpp"
#include <iostream>

Brain::Brain() {
  std::cout << __func__ << " constructor called" << std::endl;
}

Brain::Brain(const Brain& b) {
  *this = b;
}

Brain&  Brain::operator=(const Brain& b) {
  if (this == &b)
    return (*this);
  for (int i = 0; i < 100; ++i) 
    ideas[i] = b.ideas[i];
  return (*this);
}

Brain::~Brain() {
  std::cout << __func__ << " destrctor called" << std::endl;
}

Brain::Brain(const std::string &idea) {
  for (int i = 0; i < 100; ++i)
    ideas[i] = idea;
}

void  Brain::printIdea(void) const {
  if (ideas->empty())
    std::cout << "Ideas empty" << std::endl;
  else {
    for (int i = 0; i < 100; i++)
      std::cout << i + 1 << " idea : " << ideas[i] << std::endl;
  }
}