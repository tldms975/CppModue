#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <vector>
#include <iostream>
#include <exception>

class UnknownValueException : public std::exception
{
	public:
		const char* what() const throw();
};

template <typename T>
typename T::iterator easyfind(T &container, int n)
{
	typename T::iterator it = std::find(container.begin(), container.end(), n);
	if (it == container.end())
		throw UnknownValueException();
	return it;
}

#endif