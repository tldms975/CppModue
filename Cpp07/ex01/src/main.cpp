#include "iter.hpp"
#include <iostream>
#include <string>

int main()
{
	int arr[] = {1, 2, 3, 4, 5};

	iter(arr, sizeof(arr)/sizeof(int), print);
	std::cout << std::endl;
	iter(arr, sizeof(arr)/sizeof(int), addOne);
	std::cout << std::endl;
	iter(arr, sizeof(arr)/sizeof(int), print);
	std::cout << std::endl;

	std::cout << std::endl;

	std::string arr2[] = {"sd", "asdf", "qwer"};

	iter(arr2, sizeof(arr2)/sizeof(std::string), print);
	std::cout << std::endl;
	iter(arr2, sizeof(arr2)/sizeof(std::string), addOne);
	iter(arr2, sizeof(arr2)/sizeof(std::string), print);
	std::cout << std::endl;

	
	return 0;
}
