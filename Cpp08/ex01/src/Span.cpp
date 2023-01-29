#include "Span.hpp"
#include <iostream>
#include <cstdlib> // random
#include <ctime> // time

Span::Span() : _n(0)
{
}

Span::Span(unsigned int n) : _n(n)
{
}

Span::Span(const Span& c) : _n(c._n), _v(c._v)
{
}

Span& Span::operator=(const Span& c)
{
	if (this == &c)
		return (*this);
	this->_n = c._n;
	this->_v = c._v;
	return (*this);
}

Span::~Span()
{
}

void	Span::addNumber(int n)
{
	if (this->_v.size() < this->_n)
		this->_v.push_back(n);
	else
		throw FullException();
}

int		Span::shortestSpan()
{
	if (this->_v.size() <= 1)
		throw NotEnoughException();
	std::vector<int> v = this->_v;
	std::vector<int>::iterator it;
	std::sort(v.begin(), v.end());
	int min = v[1] - v[0];
	for (it = v.begin(); it != v.end() - 1; it++)
	{
		if (*(it + 1) - *it < min)
			min = *(it + 1) - *it;
	}
	return (min);
}

int		Span::longestSpan()
{
	if (this->_v.size() <= 1)
		throw NotEnoughException();
	std::vector<int> v = this->_v;
	std::sort(v.begin(), v.end());
	return (v[v.size() - 1] - v[0]);
}

const char* Span::FullException::what() const throw()
{
	return ("Span is full");
}

const char* Span::NotEnoughException::what() const throw()
{
	return ("Not enough elements");
}

void	Span::addNumberAutomatically()
{
	unsigned int num;
	std::srand(std::time(NULL));

	std::cout << "Fill the vector with random numbers.." << std::endl;
	while (_v.size() < this->_n)
	{
		num = std::rand() % 100000;
		this->_v.push_back(num);
		std::cout << "Add number of " << num << std::endl;
	}
}