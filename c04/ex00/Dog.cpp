#include <iostream>
#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& d) {
	*this = d;
}

Dog&	Dog::operator=(const Dog& d) {
	if (this == &d)
		return (*this);
	_type = d._type;
	return (*this);
}

Dog::~Dog() {
	std::cout << "Dog default destructor called" << std::endl;
}

void	Dog::makeSound(void) const {
	std::cout << "Woof!!" << std::endl;
}

std::string	Dog::getType(void) const {
	return (_type);
}

void	Dog::setType(const std::string &type) {
	_type = type;
}
