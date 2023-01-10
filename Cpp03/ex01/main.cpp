#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ClapTrap A = ClapTrap("A");
	ScavTrap B = ScavTrap("B");

	A.attack("B");
	B.attack("A");
	A.takeDamage(10);
	A.beRepaired(100);
	B.beRepaired(100);
	B.takeDamage(10);
	A.printStatus();
	B.printStatus();
	B.guardGate();
	return (0);
}