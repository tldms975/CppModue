#include <iostream>
#include "Array.hpp"

int main(int, char**)
{
	Array<int> t1(5);
	Array<int> t2;

	try
	{
		t2[0] = 1;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	try
	{
		for (unsigned int i = 0; i < t1.size(); i++)
		{
			t1[i] = i;
			std::cout << "t1[" << i << "]: " << t1[i] << std::endl;
		}
		std::cout << ">> t1[0] = 2\n";
		t1[0] = 2;
		std::cout << "t1[0]: " << t1[0] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	try{
		Array<int> t2 = t1;
		for (unsigned int i = 0; i < t2.size(); i++)
		{
			std::cout << "t2[" << i << "]: " << t2[i] << std::endl;
		}
		if (&t2 == &t1)
			std::cout << "Shallow copy" << std::endl;
		else
			std::cout << "Deep copy" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	// system("leaks ex02.exe");
	return 0;
}