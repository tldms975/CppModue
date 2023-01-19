#ifndef FORM_HPP
#define FORM_HPP
#include <string>
#include <exception>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		bool _signed;
		const int _gradeToSign;
		const int _gradeToExecute;
	public:
		Form();
		Form(std::string name, int gradeToSign, int gradeToExecute);
		Form(Form const & o);
		~Form();
		Form & operator=(Form const & o);
		std::string getName() const;
		bool getSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		void	beSigned(Bureaucrat const & bureaucrat);
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

};

std::ostream& operator<<(std::ostream & o, Form const & form);

#endif 