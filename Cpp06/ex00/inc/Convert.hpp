#ifndef CONVERT_HPP
#define CONVERT_HPP
#include <string>
#include <exception>
#include <iostream>

class Convert
{
	private:
		std::string	_str;
		double		_d;
		char		*_endptr;
		Convert();
	public:
		Convert(std::string input);
		Convert(Convert const & o);
		~Convert();
		Convert & operator=(Convert const & o);

		static bool ft_isinf(double d);
		static bool ft_isnan(double d);
		static bool ft_isdemical(double d);

		char	toChar();
		int		toInt();
		float	toFloat();
		double	toDouble();
		
		void	printChar();
		void	printInt();
		void	printFloat();
		void	printDouble();

		class NonDisplayableException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class ImpossibleException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream &o, Convert &convert);

#endif