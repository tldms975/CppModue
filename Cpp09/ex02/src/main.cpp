#include "PmergeMe.hpp"
#include <iostream>

int main(int ac, char *av[])
{
	try
	{
		PmergeMe pmm(ac, av);
		pmm.printResult();
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << "\n";
	}
	return (0);
}