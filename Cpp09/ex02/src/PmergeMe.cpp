#include "PmergeMe.hpp"
#include <iostream>
#include <cstdlib>

void	PmergeMe::parseString(std::string str)
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] == ' ')
		{
			char		*endptr;
			int			num = std::strtol((str.substr(0, i)).c_str(), &endptr, 10);
			if (*endptr != '\0' || num < 0)
				throw InvalidArgumentException();
			_lst.push_back(num);
			_vec.push_back(num);
			str.erase(0, i + 1);
		}
	}
	if (str.size() > 0)
	{
		char		*endptr;
		int			num = std::strtol((str.substr(0, str.length())).c_str(), &endptr, 10);
		if (*endptr != '\0' || num < 0)
			throw InvalidArgumentException();
		_lst.push_back(num);
		_vec.push_back(num);
	}
	_size = _lst.size();
}

void PmergeMe::parseArguements(int ac, char *av[]) 
{
	for (int i = 1; i < ac; i++)
	{
		char *endptr;
		int num = std::strtol(av[i], &endptr, 10);
		if (*endptr != '\0' || num < 0)
			throw InvalidArgumentException();
		_lst.push_back(num);
		_vec.push_back(num);
	}
	_size = _lst.size();
}

PmergeMe::PmergeMe(int ac, char *av[]) 
{
	if (ac == 2)
		parseString(av[1]);
	else
		parseArguements(ac, av);
	if (_size < 2)
		throw InvalidArgumentException();
}

PmergeMe::~PmergeMe()
{
}

PmergeMe::PmergeMe(PmergeMe const &o) 
: _lst(o._lst), _vec(o._vec), _size(o._size)
{
}

PmergeMe &PmergeMe::operator=(PmergeMe const &o)
{
	if (this != &o)
	{
		this->_lst = o._lst;
		this->_vec = o._vec;
		this->_size = o._size;
	}
	return (*this);
}

double PmergeMe::mergeInsertLst()
{
	clock_t	start, end;
	start = std::clock();
	std::list<int>::iterator it = _lst.begin();
	std::list<int>::iterator it2 = _lst.begin();
	it2++;
	while (it2 != _lst.end())
	{
		if (*it > *it2)
		{
			int tmp = *it;
			*it = *it2;
			*it2 = tmp;
			it = _lst.begin();
			it2 = _lst.begin();
			it2++;
		}
		else
		{
			it++;
			it2++;
		}
	}
	end = std::clock();
	return ((double)(end - start) / CLOCKS_PER_SEC * 1000000);
}

double PmergeMe::mergeInsertVec()
{
	clock_t	start, end;
	start = std::clock();
	std::vector<int>::iterator it = _vec.begin();
	std::vector<int>::iterator it2 = _vec.begin();
	it2++;
	while (it2 != _vec.end())
	{
		if (*it > *it2)
		{
			int tmp = *it;
			*it = *it2;
			*it2 = tmp;
			it = _vec.begin();
			it2 = _vec.begin();
			it2++;
		}
		else
		{
			it++;
			it2++;
		}
	}
	end = std::clock();
	return ((double)(end - start) / CLOCKS_PER_SEC * 1000000);
}

void PmergeMe::printResult()
{
	double	timeLst, timeVec;
	std::cout << "Before:\t";
	for (std::list<int>::iterator it = _lst.begin(); it != _lst.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	timeLst = mergeInsertLst();
	timeVec = mergeInsertVec();

	std::cout << "After:\t";
	for (std::vector<int>::iterator it = _vec.begin(); it != _vec.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "Time to process a range of " << _size <<" elements with std::list : " << timeLst << " us\n";
	std::cout << "Time to process a range of " << _size <<" elements with std::vector : " << timeVec << " us\n";
}