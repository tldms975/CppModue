#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat const & o) : _name(o._name), _grade(o._grade)
{
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & rhs)
{
	_grade = rhs._grade;
	return *this;
}

std::ostream& operator<<(std::ostream & o, Bureaucrat const & rhs)
{
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << std::endl;
	return o;
}

std::string Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::incrementGrade()
{
	if (_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade++;
}