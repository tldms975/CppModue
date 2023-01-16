#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	this->_cnt = 0;
	for (int i = 0; i < 4; i++)
		this->_materia[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &o)
{
	this->_cnt = o._cnt;
	for (int i = 0; i < 4; i++)
		this->_materia[i] = o._materia[i];
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materia[i])
			delete this->_materia[i];
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &o)
{
	if (this != &o)
	{
		this->_cnt = o._cnt;
		for (int i = 0; i < 4; i++)
		{
			if (this->_materia[i])
				delete this->_materia[i];
			this->_materia[i] = o._materia[i];
		}
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria *m)
{
	if (this->_cnt < 4)
	{
		this->_materia[this->_cnt] = m;
		this->_cnt++;
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materia[i] && this->_materia[i]->getType() == type)
			return (this->_materia[i]->clone());
	}
	return (0);
}
