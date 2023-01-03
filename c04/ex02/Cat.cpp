#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal("Cat"), brain(new Brain()) {
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& c) {
	*this = c;
}

Cat& Cat::operator=(const Cat& c) {
	if (this == &c)
		return (*this);
	if (brain != NULL) {
		delete brain;
		brain = NULL;
	}
	_type = c._type;
	brain = new Brain(*c.brain);
	return (*this);
}

Cat::~Cat() {
	if (brain != NULL)
		delete brain;
	std::cout << "Cat default destructor called" << std::endl;
}

Cat::Cat(const std::string& idea) : Animal("Cat"), brain(new Brain(idea)) {
	std::cout << "Cat idea constructor called" << std::endl;
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

Brain*	Cat::getBrain(void) const {
	return (brain);
}