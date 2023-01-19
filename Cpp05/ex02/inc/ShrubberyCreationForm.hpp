#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include "Form.hpp"
#include <string>
#include <exception>

class ShrubberyCreationForm : public Form
{
	private:
		std::string _target;
		void execute(Bureaucrat const & executor) const;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const & o);
		~ShrubberyCreationForm();
		ShrubberyCreationForm & operator=(ShrubberyCreationForm const & o);
		class FileErrorException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif