#include "Cure.hpp"
#include <iostream>

Cure::Cure() : AMateria("cure")
{
}

Cure::Cure(const Cure& o) : AMateria(o)
{
}

Cure::~Cure()
{
}

Cure& Cure::operator=(const Cure& o)
{
	if (this != &o)
		AMateria::operator=(o);
	return (*this);
}

AMateria* Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
	AMateria::use(target);
}
