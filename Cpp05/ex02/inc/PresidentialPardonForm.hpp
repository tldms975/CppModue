#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form
{
	private:
		std::string _target;
		void execute(Bureaucrat const & executor) const;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm const & o);
		~PresidentialPardonForm();
		PresidentialPardonForm & operator=(PresidentialPardonForm const & o);
};

#endif