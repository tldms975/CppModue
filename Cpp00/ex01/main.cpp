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
		if (input.compare("ADD") == 0)
			phoneBook.add();
		else if (input.compare("SEARCH") == 0)
			phoneBook.search();
		else if (input.compare("EXIT") == 0)
			phoneBook.exit();
		else
			;
	}
}