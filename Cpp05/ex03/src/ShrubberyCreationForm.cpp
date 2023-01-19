#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
 : Form("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & o)
 : Form("ShrubberyCreationForm", 145, 137), _target(o._target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & o)
{
	if (this == &o)
		return (*this);
	_target = o._target;
	return *this;
}

const char* ShrubberyCreationForm::FileErrorException::what() const throw()
{
	return "File error";
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->getGradeToExecute())
		throw Form::GradeTooLowException();
	if (!this->getSigned())
		throw Form::NotSignedException();
	std::ofstream ofs(this->_target + "_shrubbery");
	if (!ofs.good())
		throw ShrubberyCreationForm::FileErrorException();
	ofs << "      ." << std::endl;
	ofs << "   __/ \\__" << std::endl;
	ofs << "   \\     /" << std::endl;
	ofs << "   /.'o'.\\" << std::endl;
	ofs << "    .o.'." << std::endl;
	ofs << "   .'.'o'." << std::endl;
	ofs << "  o'.o.'.o." << std::endl;
	ofs << " .'.o.'.'.o." << std::endl;
	ofs << ".o.'.o.'.o.'." << std::endl;
	ofs << "   [_____]" << std::endl;
	ofs << "    \\___/" << std::endl;
	ofs.close();
}
