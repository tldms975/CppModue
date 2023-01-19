#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Form f1("f1", 1, 1);
	Form f2(f1);
	if (&f2 == &f1)
		std::cout << "f2 == f1" << std::endl;
	else
		std::cout << "f2 != f1" << std::endl;
	try
	{
		Bureaucrat b1("b1", 1);
		b1.signForm(f1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat b1("b1", 10);
		b1.signForm(f1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}