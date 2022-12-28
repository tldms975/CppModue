#include <iostream>
#include <string>

int	main(void)
{
	std::string	str = "HI THIS IS BARIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "[memory]\n";
	std::cout << "str: " << &str << "\n";
	std::cout << "stringPTR: " << stringPTR << "\n";
	std::cout << "stringREF: " << &stringREF << "\n";
	
	std::cout << "\n[value]\n";
	std::cout << "str: " << str << "\n";
	std::cout << "stringPTR: " << *stringPTR << "\n";
	std::cout << "stringREF: " << stringREF << "\n";
}
