#include "Convert.hpp"
#include <iostream>

int main(int ac, char *av[])
{

	try
	{
		
		Convert convert(av[1]);
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	



	return (0);
}