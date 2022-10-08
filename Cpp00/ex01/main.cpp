#include "PhoneBook.hpp"
#include <iostream>
#include <string.h>

int main(void)
{
	PhoneBook	phoneBook;
	std::string	input;

	while (true)
	{
		std::cin.clear();
		std::cout << "Enter [ADD, SEARCH, EXIT]\n";
		std::getline(std::cin, input);
		if (std::cin.fail() || std::cin.eof())
		{
			std::cout << "Wrong Input\n";
			std::cin.ignore(LLONG_MAX, '\n');
			continue ;
		}
		else if (input.compare("ADD") == 0)
			phoneBook.add();
		else if (input.compare("SEARCH") == 0)
			phoneBook.search();
		else if (input.compare("EXIT") == 0)
			phoneBook.exit();
		else
			;
	}
}