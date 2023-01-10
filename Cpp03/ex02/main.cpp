#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ClapTrap A = ClapTrap("A");
	ScavTrap B = ScavTrap("B");
	FragTrap C = FragTrap("C");

	A.attack("B");
	B.attack("C");
	C.attack("B");
	A.takeDamage(10);
	A.beRepaired(100);
	B.beRepaired(100);
	B.takeDamage(10);
	C.takeDamage(10);
	C.beRepaired(100);
	A.printStatus();
	B.printStatus();
	C.printStatus();
	B.guardGate();
	C.highFivesGuys();
	return (0);
}