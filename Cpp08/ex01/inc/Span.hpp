#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>

class Span
{
	private:
		unsigned int		_n;
		std::vector<int>	_v;
		Span();
	public:
		Span(unsigned int n);
		Span(const Span& c);
		Span& operator=(const Span& c);
		~Span();
		void addNumber(int n);
		int shortestSpan();
		int longestSpan();
		void addNumberAutomatically();

		class FullException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class NotEnoughException : public std::exception
		{
			public:
				const char* what() const throw();
		};

};

#endif
