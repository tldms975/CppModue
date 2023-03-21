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
			i = 0;
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

void PmergeMe::parseArguments(int ac, char *av[]) 
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
		parseArguments(ac, av);
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

// vector sort
void	PmergeMe::mergeInsertVec(int left, int right)
{
	if (left < right)
	{
		int size = right - left + 1;

		if (size < 20)
			insertionSortVec(left, right);
		else
		{
			int	mid = left + (right - left) / 2;
			mergeInsertVec(left, mid);
			mergeInsertVec(mid + 1, right);
			mergeVector(left, mid, right);
		}
	}
}

void	PmergeMe::insertionSortVec(int left, int right)
{
	for (int i = left + 1; i <= right; i++)
	{
		int key = _vec[i];
		int j = i - 1;
		while (j >= left && _vec[j] > key)
		{
			_vec[j + 1] = _vec[j];
			j--;
		}
		_vec[j + 1] = key;
	}
}

void	PmergeMe::mergeVector(int left, int mid, int right)
{
	int		i = left;
	int		j = mid + 1;
	int		k = 0;
	std::vector<int> tmp(right - left + 1);

	while (i <= mid && j <= right)
	{
		if (_vec[i] <= _vec[j])
			tmp[k++] = _vec[i++];
		else
			tmp[k++] = _vec[j++];
	}
	while (i <= mid)
		tmp[k++] = _vec[i++];
	while (j <= right)
		tmp[k++] = _vec[j++];
	for (int i = left, k = 0; i <= right; i++, k++)
		_vec[i] = tmp[k];
}

// list sort
void	PmergeMe::mergeInsertLst(std::list<int> &lst)
{
	if (lst.size() < 20)
		insertionSortLst(lst);
	else
	{
		std::list<int> left;
		std::list<int> right;
		int mid = lst.size() / 2;
		std::list<int>::iterator it = lst.begin();
		for (int i = 0; i < mid; i++)
		{
			left.push_back(*it);
			it++;
		}
		for (int i = mid; i < (int)lst.size(); i++)
		{
			right.push_back(*it);
			it++;
		}
		mergeInsertLst(left);
		mergeInsertLst(right);
		mergeList(lst, left, right);
	}
}

void	PmergeMe::insertionSortLst(std::list<int> &lst)
{
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); it++)
	{
		std::list<int>::iterator it2 = it;
		it2--;
		while (it2 != lst.begin() && *it2 > *it)
			it2--;
		if (*it2 > *it)
		{
			lst.erase(it);
			lst.push_front(*it);
		}
		else
		{
			lst.erase(it);
			it2++;
			lst.insert(it2, *it);
		}
	}
}

void	PmergeMe::mergeList(std::list<int> &lst, std::list<int> &left, std::list<int> &right)
{
	std::list<int>::iterator it = lst.begin();
	std::list<int>::iterator itLeft = left.begin();
	std::list<int>::iterator itRight = right.begin();
	while (itLeft != left.end() && itRight != right.end())
	{
		if (*itLeft <= *itRight)
		{
			*it = *itLeft;
			itLeft++;
		}
		else
		{
			*it = *itRight;
			itRight++;
		}
		it++;
	}
	while (itLeft != left.end())
	{
		*it = *itLeft;
		itLeft++;
		it++;
	}
	while (itRight != right.end())
	{
		*it = *itRight;
		itRight++;
		it++;
	}
}

// getTime
double PmergeMe::getRunTimeLst()
{
	clock_t	start, end;
	start = std::clock();
	mergeInsertLst(_lst);
	end = std::clock();
	return ((double)(end - start) / CLOCKS_PER_SEC * 1000000);
}

double PmergeMe::getRunTimeVec()
{
	clock_t	start, end;
	start = std::clock();
	mergeInsertVec(0, _size - 1);
	end = std::clock();
	return ((double)(end - start) / CLOCKS_PER_SEC * 1000000);
}

void PmergeMe::printResult()
{
	double	timeLst = 0, timeVec = 0;
	std::cout << "Before:\t";
	for (std::list<int>::iterator it = _lst.begin(); it != _lst.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	if (_size > 1)
	{
		timeLst = getRunTimeLst();
		timeVec = getRunTimeVec();
	}

	std::cout << "After:\t";
	for (std::vector<int>::iterator it = _vec.begin(); it != _vec.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "Time to process a range of " << _size <<" elements with std::list : " << timeLst << " us\n";
	std::cout << "Time to process a range of " << _size <<" elements with std::vector : " << timeVec << " us\n";
}