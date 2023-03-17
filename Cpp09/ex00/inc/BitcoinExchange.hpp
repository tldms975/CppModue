#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
#include <map>
#include <exception>

class BitcoinExchange
{
	private:
		std::map <std::string, float>	_data;
	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &ref);
		BitcoinExchange &operator=(const BitcoinExchange &ref);

		void run(std::string input);
		void printResult(std::string date, float value);

		class EmptyDataException : public std::exception
		{
			public:
				const char *what() const throw()
				{
					return ("Error: Empty data");
				}
		};

		class NotAValidNumberException : public std::exception
		{
			public:
				const char *what() const throw()
				{
					return ("Error: Invalid number");
				}
		};

		class NegativeNumberException : public std::exception
		{
			public:
				const char *what() const throw()
				{
					return ("Error: value must be positive");
				}
		};

		class NumberTooLargeException : public std::exception
		{
			public:
				const char *what() const throw()
				{
					return ("Error: Number is too large");
				}
		};

		class NotAValidDateException : public std::exception
		{
			public:
				const char *what() const throw()
				{
					return ("Error: Not a valid date");
				}
		};
};

#endif