#include "whatever.hpp"
#include <iostream>
#include <string>

int main(void)
{
	{
		int a = 2;
		int b = 3;

		::swap(a, b);
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min:(a, b) = " << ::min( a, b ) << std::endl;
		std::cout << "max:(a, b) = " << ::max( a, b ) << std::endl;

		std::string c = "chaine1";
		std::string d = "chaine2";

		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min:(c, d) = " << ::min( c, d ) << std::endl;
		std::cout << "max:(c, d) = " << ::max( c, d ) << std::endl;
	}

	// {
	// 	int c1 = 3;
	// 	int c2 = 3;

	// 	std::cout << "===============[TEST 1]===============" << std::endl;
	// 	std::cout << "c1 = " << c1 << ", c2 = " << c2 << std::endl;
	// 	std::cout << "min:(a, b) = " << ::min( c1, c2 ) << std::endl;
	// 	std::cout << "max:(a, b) = " << ::max( c1, c2 ) << std::endl;
	// 	::swap(c1, c2);
	// 	std::cout << "swap..." << std::endl;
	// 	std::cout << "c1 = " << c1 << ", c2 = " << c2 << std::endl;
	// 	std::cout << "======================================" << std::endl;
	// }
	return 0;
}