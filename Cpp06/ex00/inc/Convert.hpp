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

		void	setInput(std::string input);

		char	toChar();
		int		toInt();
		float	toFloat();
		double	toDouble();
		
		void	printChar();
		void	printInt();
		void	printFloat();
		void	printDouble();
		void	printAll();

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

		class NotANumberException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class InfinityException : public std::exception
		{
			public:
				const char* what() const throw();
		};

};

#endif