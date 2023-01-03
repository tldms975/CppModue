#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal("Cat") {
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& c) {
	*this = c;
}

Cat& Cat::operator=(const Cat& c) {
	if (this == &c)
		return (*this);
	_type = c._type;
	return (*this);
}

Cat::~Cat() {
	std::cout << "Cat default destructor called" << std::endl;
}

void	Cat::makeSound(void) const {
	std::cout << "Meowwwwww!!!!" << std::endl;
}

void	Cat::setType(std::string type) {
	_type = type;
}

std::string	Cat::getType(void) const {
	return (_type);
}