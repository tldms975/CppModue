#include "RPN.hpp"
#include <iostream>

int main(int ac, char **av)
{
	if (ac == 2)
	{
		RPN rpn(av[1]);
		rpn.printResult();
	}
	else
		std::cout << "Usage: ./RPN \"expression\"" << std::endl;
	return (0);
}