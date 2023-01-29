#include "easyfind.hpp"
#include <vector>
#include <iostream>

const char* UnknownValueException::what() const throw()
{
	return ("Value not found");
}

int	main()
{
	std::vector<int> v;
	std::vector<int>::iterator it;

	for (int i = 0; i < 10; i++)
		v.push_back(i);
	try
	{
		it = easyfind(v, 5);
		std::cout << "Value: " << *it << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);

}