#ifndef INTERN_HPP
#define INTERN_HPP

#include <exception>
#include "Form.hpp"

class Intern
{
	private:
	public:
		Intern();
		Intern(Intern const & o);
		~Intern();
		Intern & operator=(Intern const & o);
		Form* makeForm(const std::string &formName,const std::string &target);
		class UnknownFormException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};


#endif