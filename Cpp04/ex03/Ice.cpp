#include "Ice.hpp"
#include <iostream>

Ice::Ice() : AMateria("ice")
{
}

Ice::Ice(const Ice &o) : AMateria(o)
{
}

Ice::~Ice()
{
}

Ice &Ice::operator=(const Ice &o)
{
	if (this != &o)
		AMateria::operator=(o);
	return (*this);
}

AMateria* Ice::clone() const
{
	return (new Ice(*this));
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	AMateria::use(target);
}

