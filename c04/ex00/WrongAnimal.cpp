#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() : _type("WrongAnimal") {
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& w) {
	*this = w;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& w) {
	if (this == &w)
		return (*this);
	_type = w._type;
	return (*this);
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string& type) : _type(type) {
	std::cout << "WrongAnimal string constructor called" << std::endl;
}


void	WrongAnimal::makeSound(void) const {
	std::cout << "WrongAnimalllllll ** NOT A WRONGCAT's sound **" << std::endl;
}

void	WrongAnimal::setType(const std::string& type) {
	this->_type = type;
}

std::string	WrongAnimal::getType(void) const {
	return (this->_type);
}