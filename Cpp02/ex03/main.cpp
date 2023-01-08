#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

int main	(void)
{
	Point	a(5, 1.5), b(5, 1.5), c(5, 0);
	Point	spot(5, 0);

	if (bsp(a, b, c, spot))
		std::cout << "It's inside the triangle\n";
	else
		std::cout << "It's outside the triangle\n";
	return (0);
}