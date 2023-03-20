#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>

class RPN
{
	private:
		std::string			_input;
		RPN();
	public:
		RPN(std::string input);
		RPN(RPN const & o);
		~RPN();
		RPN & operator=(RPN const & o);
		void	calcAdd(std::stack<float> &opr);
		void	calcSub(std::stack<float> &opr);
		void	calcMul(std::stack<float> &opr);
		void	calcDiv(std::stack<float> &opr);
		void	printResult();
};

#endif