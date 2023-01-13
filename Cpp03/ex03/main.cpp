#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap	D = DiamondTrap("D");

	for (int i = 0; i < 100; i++)
		D.attack("enemy");
	D.beRepaired(1);
	D.guardGate();
	D.whoAmI();
	D.printStatus();
	return (0);
}