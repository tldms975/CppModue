#include "PhoneBook.hpp"
#include <limits>

PhoneBook::PhoneBook()
{
	this->numOfContact = 0;
	this->idx = 0;
}

PhoneBook::~PhoneBook()
{
}

std::string	PhoneBook::inputField(std::string field, bool &flag)
{
	std::string	str;

	while (true)
	{
		std::cout << field << ": ";
		std::getline(std::cin, str);
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Wrong Input" << std::endl;
			flag = 1;
			return (str);
		}
		else if (str.empty())
			std::cout << "Empty input is not allowed.\n";
		else
			return (str);
	}
}

void	PhoneBook::add()
{
	std::string	info[5];
	std::string	field[5] = \
	{"First name", "Last name", "Nickname", "Phone Number", "Darkest Secret"};
	bool		flag = 0;

	for (int i = 0; i < 5; i++)
	{
		if (flag == 0)
			info[i] = inputField(field[i], flag);
		else
		{
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return ;
		}
	}
	contact[idx % 8].saveInfo(info);
	numOfContact++;
	idx++;
	if (idx > 7)
		idx = 0;
	if (numOfContact > 8)
		numOfContact = 8;
	std::cout << "\nSuccessfully Added!\n\n";
	return ;
}

void	PhoneBook::search()
{
	std::string	contour = "-------------------------------------------\n";
	std::string	showLine = "###########################################\n";
	int	idx = -1;

	std::cout << std::setw(10) << std::right << "Index" << "|";
	std::cout << std::setw(10) << std::right << "FirstName" << "|";
	std::cout << std::setw(10) << std::right << "LastName" << "|";
	std::cout << std::setw(10) << std::right << "Nickname" << "\n";
	std::cout << contour;
	for (int i = 0; i < numOfContact; i++)
	{
		contact[i].displayContacts(i);
		std::cout << contour;
	}
	std::cout << "Input the index: ";
	std::cin >> idx;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	if (std::cin.fail())
	{
		if (std::cin.eof())
			return ;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // or you'll get 2 outputs
		std::cout << "Please input the NUMBER\n\n";
		return ;
	}
	if ((idx < 0 || idx > 8) || (idx >= numOfContact))
	{
		std::cout << "Out of Range\n";
		return ;
	}
	else
	{
		std::cout << "\n" << showLine;
		contact[idx].showContact();
		std::cout << showLine << "\n";
		return ;
	}
}

void	PhoneBook::exit()
{
	std::cout << "Bye" << std::endl;
	std::exit(0);
}