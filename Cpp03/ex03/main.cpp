#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap	D = DiamondTrap("D");


	D.attack("enemy");
	D.whoAmI();
	D.printStatus();
	return (0);
}