#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

// void bye()
// {
// 	system("leaks ex03.exe");
// }

int main()
{
	//atexit(bye);
	try
	{
		Intern	someRandomIntern;
		Form*	rrf;

		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		std::cout << *rrf;
		delete rrf;//undo unless leaks
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;
	try
	{
		Intern	someRandomIntern;
		Form*	rrf;

		rrf = someRandomIntern.makeForm("shrubbery creation", "tree");
		std::cout << *rrf;
		Bureaucrat b("bureaucrat", 1);
		b.signForm(*rrf);
		b.executeForm(*rrf);
		delete rrf;//undo unless leaks
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;
	try
	{
		Intern	someRandomIntern;
		Form*	rrf;

		rrf = someRandomIntern.makeForm("presidential pardon", "president");
		std::cout << *rrf;
		Bureaucrat b("bureaucrat", 1);
		b.signForm(*rrf);
		b.executeForm(*rrf);
		delete rrf;//undo unless leaks
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	try
	{
		Intern	someRandomIntern;
		Form*	rrf;

		rrf = someRandomIntern.makeForm("", "");
		std::cout << *rrf;
		delete rrf;//undo unless leaks
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}