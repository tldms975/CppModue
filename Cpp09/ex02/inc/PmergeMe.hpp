#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <string>
#include <list>
#include <vector>
#include <exception>
#include <ctime>

class PmergeMe
{
	private:
		std::list<int>		_lst;
		std::vector<int>	_vec;
		int					_size;
		void				parseString(std::string str);
		void				parseArguements(int ac, char *av[]);
		double				mergeInsertLst();
		double				mergeInsertVec();
		PmergeMe();

	public:
		PmergeMe(int ac, char *av[]);
		~PmergeMe();
		PmergeMe(PmergeMe const &o);
		PmergeMe &operator=(PmergeMe const &o);
		void	printResult();
		class InvalidArgumentException : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return ("Error: positive integer sequence is only allowed");
				}
		};
};

#endif