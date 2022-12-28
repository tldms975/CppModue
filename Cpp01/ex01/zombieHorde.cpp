#include "Zombie.hpp"
#include <string>
#include <iostream>

Zombie*	zombieHorde(int N, std::string name)
{
	Zombie	*ret = new Zombie[N];

	for (int i = 0; i < N; i++)
	{
		ret[i].setName(name + " " + std::to_string(i));
		ret[i].announce();
	}
	return (ret);
}
