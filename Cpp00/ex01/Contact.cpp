#include "Contact.hpp"
#include <iostream>
#include <iomanip>

Contact::Contact()
{
}

Contact::~Contact()
{
}

void	Contact::saveInfo(std::string info[5])
{
	this->firstName = info[0];
	this->lastName = info[1];
	this->nickname = info[2];
	this->phoneNumber = info[3];
	this->darkestSecret = info[4];
}

void	Contact::displayField(std::string field)
{
	std::string	s;

	if (field.length() > 10)
		s = field.substr(0, 9) + '.';
	else
		s = field;
	std::cout << std::setw(10) << std::right << s;
}

void	Contact::displayContacts(int idx)
{
	std::cout << std::setw(10) << std::right << idx;
	std::cout << "|";
	displayField(firstName);
	std::cout << "|";
	displayField(lastName);
	std::cout << "|";
	displayField(nickname);
	std::cout << "\n";
}

void	Contact::showContact()
{
	std::cout << "first name: " << firstName << "\n";
	std::cout << "last name: " << lastName << "\n";
	std::cout << "nickname: " << nickname << "\n";
	std::cout << "phone number: " << phoneNumber << "\n";
}
