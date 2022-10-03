#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->numOfContact = 0;
}

PhoneBook::~PhoneBook()
{
}

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
	contact[numOfContact % 8].saveInfo(info);
	numOfContact++;
}

void	PhoneBook::displayContact(Contact &contact)
{
	
}

void	PhoneBook::search()
{
	std::string	input;
	int			idx;

	std::cout << "Enter the index >> ";
	std::getline(std::cin, input);
	displayContact(contact[idx]);
}

void	PhoneBook::exit()
{
	std::exit(0);
}