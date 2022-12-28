#include "HumanA.hpp"
#include <iostream>

void	HumanA::attack()
{
	std::cout << this->_name << " attacks with their " << this->weapon.getType() << "\n";
}