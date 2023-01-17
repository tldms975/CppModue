#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat b1("b1", 1);
	Bureaucrat b2("b2", 150);
	Bureaucrat b3("b3", 2);

	try
	{
		b1.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		b2.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}