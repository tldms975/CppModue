#include "RPN.hpp"
#include <iostream>

RPN::RPN(std::string input) : _input(input)
{
}

RPN::RPN(RPN const & o) : _input(o._input)
{
}

RPN::~RPN()
{
}

RPN & RPN::operator=(RPN const & o)
{
	if (this == &o)
		return (*this);
	this->_input = o._input;
	return (*this);
}

void	RPN::calcAdd(std::stack<float> &opr)
{
	float tmp = opr.top(), res = 0;
	opr.pop();
	res += opr.top() + tmp;
	opr.pop();
	opr.push(res);
}

void	RPN::calcSub(std::stack<float> &opr)
{
	float tmp = opr.top(), res = 0;
	opr.pop();
	res += opr.top() - tmp;
	opr.pop();
	opr.push(res);
}

void	RPN::calcMul(std::stack<float> &opr)
{
	float tmp = opr.top(), res = 0;
	opr.pop();
	res += opr.top() * tmp;
	opr.pop();
	opr.push(res);
}

void	RPN::calcDiv(std::stack<float> &opr)
{
	float	tmp = opr.top(), res = 0;
	opr.pop();
	res += opr.top() / tmp;
	opr.pop();
	opr.push(res);
}

void RPN::printResult()
{
	int					len = _input.length();
	std::stack<float>	opr;
	
	for (int i = 0; i < len; i++)
	{
		char	ch = _input[i];
		if (ch == ' ');
		else if (ch >= '0' && ch <= '9')
			opr.push(ch - '0');
		else if (opr.size() > 1 && (ch == '+' || ch == '-' || ch == '*' || ch == '/'))
		{
			if (ch == '+')
				calcAdd(opr);
			else if (ch == '-')
				calcSub(opr);
			else if (ch == '*')
				calcMul(opr);
			else if (ch == '/')
				calcDiv(opr);
		}
		else
		{
			std::cout << "Error\n";
			return ;
		}
	}
	if (opr.size() == 1)
		std::cout << opr.top() << std::endl;
	else
		std::cout << "Error\n";
}

