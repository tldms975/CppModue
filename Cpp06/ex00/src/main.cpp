#include "Convert.hpp"
#include <iostream>

int main(int ac, char *av[])
{
	if (ac != 2)
	{
		std::cout << "Usage: ./ex00 [value]\n";
		return (1);
	}
	Convert c(av[1]);
	std::cout << c;
	return (0);
}