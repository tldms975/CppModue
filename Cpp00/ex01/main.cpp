#include "PhoneBook.hpp"
#include <string.h>

int main(void)
{
	PhoneBook	phoneBook;
	std::string	input;

	while (1)
	{
		std::cout << "Enter [ADD, SEARCH, EXIT]>> ";
		std::getline(std::cin, input);
		if (input.compare("ADD"))
			phoneBook.add();
		else if (input.compare("SEARCH"))
			phoneBook.search();
		else if (input.compare("EXIT"))
			phoneBook.exit();
		else
			;
	}
}