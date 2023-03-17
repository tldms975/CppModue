#include "RPN.hpp"

RPN::RPN(std::string input) : _str(input)
{
}

RPN::RPN(RPN const & o) : _str(o._str)
{
}

RPN::~RPN()
{
}

RPN & RPN::operator=(RPN const & o)
{
	_str = o._str;
	return *this;
}

