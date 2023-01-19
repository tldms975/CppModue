#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	ShrubberyCreationForm f_s("home1");
	PresidentialPardonForm f_p("home2");
	RobotomyRequestForm f_r("home3");
	std::cout << f_s;
	std::cout << f_p;
	std::cout << f_r;
	std::cout << std::endl;
	try
	{
		Bureaucrat b1("b1", 1);
		std::cout << b1;
		b1.signForm(f_s);
		b1.signForm(f_p);
		b1.signForm(f_r);
		b1.executeForm(f_s);
		b1.executeForm(f_r);
		b1.executeForm(f_p);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat b2("b2", 130);
		std::cout << b2;
		b2.signForm(f_s);
		b2.signForm(f_p);
		b2.signForm(f_r);
		b2.executeForm(f_s);
		b2.executeForm(f_p);
		b2.executeForm(f_r);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	
	return 0;
}