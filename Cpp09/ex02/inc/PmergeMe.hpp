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
		void				parseArguments(int ac, char *av[]);
		void				mergeInsertLst(std::list<int> &lst);
		void				mergeList(std::list<int> &lst, std::list<int> &left, std::list<int> &right);
		void				insertionSortLst(std::list<int> &lst);
		void				mergeInsertVec(int left, int right);
		void				mergeVector(int left, int mid, int right);
		void				insertionSortVec(int left, int right);

		double				getRunTimeLst();
		double				getRunTimeVec();
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