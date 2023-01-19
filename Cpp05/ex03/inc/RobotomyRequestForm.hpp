#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include "Form.hpp"
class RobotomyRequestForm : public Form
{
	private:
		std::string _target;
		void execute(Bureaucrat const & executor) const;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const & o);
		~RobotomyRequestForm();
		RobotomyRequestForm & operator=(RobotomyRequestForm const & o);
};

#endif