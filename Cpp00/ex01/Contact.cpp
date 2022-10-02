#include "Contact.hpp"

Contact::Contact()
{
	//{"", "", "", ""};
}

Contact::~Contact()
{
}

void	Contact::saveInfo(std::string info[5])
{
	firstName = info[0];
	lastName = info[1];
	nickname = info[2];
	phoneNumber = info[3];
	darkestSecret = info[4];
}

void	Contact::displayInfo()
{
	std::cout << "first name: " << firstName << " |";
	std::cout << "last name: " << lastName << " |";
	std::cout << "nickname: " << nickname << " |";
	std::cout << "phone number: " << phoneNumber << "\n";
}
