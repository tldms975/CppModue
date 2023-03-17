#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <iostream>

class RPN
{
	private:
		std::string	_str;
		RPN();
	public:
		RPN(std::string input);
		RPN(RPN const & o);
		~RPN();
		RPN & operator=(RPN const & o);

		void	print();
};

#endif