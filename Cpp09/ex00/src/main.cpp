#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream> // file open
#include <string> // getline

int main(int ac, char **av)
{
	try
	{
		BitcoinExchange be;

		if (ac != 2)
		{
			std::cout << "Error: could not open file.\n";
			return 1;
		}
		std::ifstream infile(av[1]);
		if (!infile.is_open())
		{
			std::cout << "Error: could not open file.\n";
			return (1);
		}
		std::string line;
		while (std::getline(infile, line))
			be.run(line);
		infile.close();
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
