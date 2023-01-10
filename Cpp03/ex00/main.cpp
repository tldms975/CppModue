#include "ClapTrap.hpp"

int main()
{
	ClapTrap clapTrap("A");
	clapTrap.attack("enemy");
	clapTrap.beRepaired(100);
	clapTrap.takeDamage(10);
	return (0);
}