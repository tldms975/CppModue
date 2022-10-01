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
	std::cin >> info[0];
	std::cin >> info[1];
	std::cin >> info[2];
	std::cin >> info[3];
	std::cin >> info[4];
}

void	Contact::displayInfo()
{
	std::cout << "first name: " << firstName << " |";
	std::cout << "last name: " << lastName << " |";
	std::cout << "nickname: " << nickname << " |";
	std::cout << "phone number: " << phoneNumber << "\n";
}
