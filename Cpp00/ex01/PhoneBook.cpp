#include "PhoneBook.hpp"

void	PhoneBook::add()
{
	std::string info[5];

	std::cout << "Enter the first name: ";
	std::cin >> info[0];
	std::cout << "Enter the last name: ";
	std::cin >> info[1];
	std::cout << "Enter the nickname: ";
	std::cin >> info[2];
	std::cout << "Enter the phone number: ";
	std::cin >> info[3];
	std::cout << "Enter the darkest secret: ";
	std::cin >> info[4];
	contact->saveInfo(info);
}

void	PhoneBook::search()
{
	int	inputIdx;

	for (int i = 0; i < num_contact; i++)
		displayContact(contact[i]);
	std::cout << "Enter the index >> ";

}

void	PhoneBook::exit()
{
	std::exit(0);
}