#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

Intern::Intern()
{
}

Intern::Intern(Intern const & o)
{
	(void)o;
	std::cout << "Intern Copy Constructor called But can't do anything\n";
}

Intern::~Intern()
{
}

Intern & Intern::operator=(Intern const & o)
{
	std::cout << "Intern operator= called But can't do anything\n";
	if (this == &o)
		return (*this);
	return *this;
}

Form * Intern::makeForm(const std::string &formName, const std::string &target)
{
	const std::string	formNames[3] \
	= {"presidential pardon", "robotomy request", "shrubbery creation"};
	Form *form = NULL;

	for(int i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
		{
			switch (i)
			{
				case 0:
					form = new PresidentialPardonForm(target);
					break;
				case 1:
					form = new RobotomyRequestForm(target);
					break;
				case 2:
					form = new ShrubberyCreationForm(target);
					break;
			}
			std::cout << "Intern creates " << formName << std::endl;
			return form;
		}
	}
	throw Intern::UnknownFormException();
	return form;
}

const char * Intern::UnknownFormException::what() const throw()
{
	return "Intern doesn't know this form";
}