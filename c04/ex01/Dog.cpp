#include <iostream>
#include "Dog.hpp"

Dog::Dog() : Animal("Dog"), brain(new Brain()) {
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& d) {
	*this = d;
}

Dog&	Dog::operator=(const Dog& d) {
	if (this == &d)
		return (*this);
	if (brain != NULL) {
		delete brain;
		brain = NULL;
	}
	_type = d._type;
	brain = new Brain(*d.brain);
	return (*this);
}

Dog::~Dog() {
	if (brain != NULL)
		delete brain;
	std::cout << "Dog default destructor called" << std::endl;
}

Dog::Dog(const std::string& idea) : Animal("Dog"), brain(new Brain(idea)) {
	std::cout << "Dog idea constructor called" << std::endl;
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

Brain*	Dog::getBrain(void) const {
	return (brain);
}