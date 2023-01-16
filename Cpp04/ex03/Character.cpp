#include "Character.hpp"

Character::Character()
{
}

Character::Character(std::string name) : _name(name)
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(const Character& o)
{
	this->_name = o._name;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = o._inventory[i];
}

Character::~Character()
{
}

Character& Character::operator=(const Character& o)
{
	if (this != &o)
	{
		this->_name = o._name;
		for (int i = 0; i < 4; i++)
			this->_inventory[i] = o._inventory[i];
	}
	return (*this);
}

std::string const &Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!this->_inventory[i])
		{
			this->_inventory[i] = m;
			return ;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
		return ;
	if (this->_inventory[idx])
		this->_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
		return ;
	if (this->_inventory[idx])
		this->_inventory[idx]->use(target);
}
