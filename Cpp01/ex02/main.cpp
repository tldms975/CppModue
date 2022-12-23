#include "Zombie.hpp"

int	main(void)
{
	Zombie	stack = Zombie("stack");
	Zombie *heap = new Zombie("heap");
	Zombie *newone = newZombie("newZombie");

	stack.announce();
	heap->announce();
	newone->announce();
	randomChump("randomChump");
	delete newone;
	delete heap;
}
