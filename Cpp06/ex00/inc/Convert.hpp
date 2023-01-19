#ifndef CONVERT_HPP
#define CONVERT_HPP
#include <string>
#include <exception>

class Convert
{
	private:
		std::string	_input;
		char		_c;
		int			_i;
		float		_f;
		double		_d;
		Convert();
	public:
		Convert(std::string input);
		Convert(Convert const & o);
		~Convert();
		Convert & operator=(Convert const & o);
};

#endif