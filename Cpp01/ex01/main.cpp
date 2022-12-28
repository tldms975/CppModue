#include "Zombie.hpp"

int	main(void)
{
	Zombie	*horde = zombieHorde(3, "sielee");

	delete[] horde;
}
