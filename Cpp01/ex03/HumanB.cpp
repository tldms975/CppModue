#include "HumanB.hpp"
#include <iostream>

void	HumanB::attack()
{
	std::cout << this->name << " attacks with their " << this->weapon.getType() << "\n";
}