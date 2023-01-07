#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

int main	(void)
{
	Point	a(0, 0), b(5, 0), c(0,5);
	Point	spot(1, 1);

	if (bsp(a, b, c, spot))
		std::cout << "It's inside the triangle\n";
	else
		std::cout << "It's outside the triangle\n";
	return (0);
}