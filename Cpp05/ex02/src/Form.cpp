#include "Form.hpp"

Form::Form()
 : _name("Form"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute)
 : _name(name), _signed(false), 
 _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(Form const & o)
 : _name(o._name), _signed(o._signed), 
 _gradeToSign(o._gradeToSign), _gradeToExecute(o._gradeToExecute)
{
}

Form::~Form()
{
}

Form & Form::operator=(Form const & o)
{
	std::cout << "Form assignation operator called But can't function exactly for constant var\n";
	_signed = o._signed;
	return *this;
}

std::string Form::getName() const
{
	return _name;
}

bool Form::getSigned() const
{
	return _signed;
}

int Form::getGradeToSign() const
{
	return _gradeToSign;
}

int Form::getGradeToExecute() const
{
	return _gradeToExecute;
}

void Form::beSigned(Bureaucrat const & bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw Form::GradeTooLowException();
	else
		_signed = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

const char* Form::NotSignedException::what() const throw()
{
	return "Form is not signed";
}

std::ostream& operator<<(std::ostream & o, Form const & form)
{
	o << "Form name: " << form.getName() \
	<< ", signed: " << form.getSigned() \
	<< ", grade to sign: " << form.getGradeToSign() \
	<< ", grade to execute: " << form.getGradeToExecute()
	<< std::endl;
	return o;
}
