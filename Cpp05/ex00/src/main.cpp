#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat b1("b1", 1);
	Bureaucrat b2("b2", 150);
	b1 = b2;
	//Bureaucrat b2(b1);
	if (&b1 == &b2)
		std::cout << "b1 and b2 are the same\n";
	else
		std::cout << "b1 and b2 are different\n";
	std::cout <<b1;
	std::cout <<b2;
	try
	{
		Bureaucrat b1("b1", 1);
		b1.incrementGrade();
		std::cout << b1; //After incrementing grade
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat b2("b2", 150);
		std::cout << b2; //Before decrementing grade
		b2.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat b3("b3", 2);
		Bureaucrat b4("b4", 0);
		std::cout << b4; // below after throwing not executed
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}