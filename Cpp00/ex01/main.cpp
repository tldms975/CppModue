#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <limits>


int main(void)
{
	PhoneBook	phoneBook;
	std::string	input;

	while (true)
	{
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Wrong Input" << std::endl;
			std::exit(1);
		}
		std::cout << "Enter [ADD, SEARCH, EXIT]\n";
		std::getline(std::cin, input);
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Wrong Input" << std::endl;
			std::exit(1);
		}
		else if (input.compare("ADD") == 0)
			phoneBook.add();
		else if (input.compare("SEARCH") == 0)
			phoneBook.search();
		else if (input.compare("EXIT") == 0)
			phoneBook.exit();
		else
			std::cout << "Try again\n";
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Wrong Input" << std::endl;
			std::exit(1);
		}
	}
}