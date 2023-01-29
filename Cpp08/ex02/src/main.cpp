#include "MutantStack.hpp"
#include <iostream>
#include <stack>

int main()
{
	{
		std::cout << "-------------TEST1-------------" << std::endl;
		MutantStack<int> mstack;
		mstack.push(1);
		mstack.push(2);
		std::cout << "top: " << mstack.top() << std::endl;
		mstack.pop();
		std::cout << "size: " << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(4);
		mstack.push(5);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite) {
			std::cout << *it << std::endl;
			++it;
		}
		std::cout << "------------copy cons--------------" << std::endl;
		MutantStack<int> s(mstack);
		if (&s != &mstack)
			std::cout << "deep copy" << std::endl;
		else
			std::cout << "shallow copy" << std::endl;
		it = s.begin();
		ite = s.end();
		while (it != ite) {
			std::cout << *it << std::endl;
			++it;
		}

		{
			std::cout << "-------------TEST2-------------" << std::endl;
			MutantStack<char> mstack;
			mstack.push('a');
			mstack.push('b');
			mstack.push('c');
			mstack.push('d');
			mstack.push('e');
			MutantStack<char>::const_iterator cit = mstack.begin();
			MutantStack<char>::const_iterator cite = mstack.end();
			++cit;
			--cit;
			while (cit != cite) {
				std::cout << *cit << std::endl;
				++cit;
			}
		}
		{
			std::cout << "-------------TEST3-------------" << std::endl;
			MutantStack<double> mstack;
			mstack.push(1.0);
			mstack.push(2.0);
			mstack.push(3.0);
			mstack.push(4.0);
			mstack.push(5.0);
			MutantStack<double>::reverse_iterator rit = mstack.rbegin();
			MutantStack<double>::reverse_iterator rite = mstack.rend();
			++rit;
			--rit;
			while (rit != rite) {
				std::cout << *rit << std::endl;
				++rit;
			}
		}
		{
			std::cout << "-------------TEST4-------------" << std::endl;
			MutantStack<std::string> mstack;
			mstack.push("a");
			mstack.push("b");
			mstack.push("c");
			mstack.push("d");
			mstack.push("e");
			MutantStack<std::string>::const_reverse_iterator crit = mstack.rbegin();
			MutantStack<std::string>::const_reverse_iterator crite = mstack.rend();
			++crit;
			--crit;
			while (crit != crite) {
				std::cout << *crit << std::endl;
				++crit;
			}
		}

	}


	// std::cout << mstack.top() << std::endl;

	// mstack.pop();

	// std::cout << mstack.size() << std::endl;

	// std::cout << "-------------main MutantStack test-------------" << std::endl;
	// mstack.push(3);
	// mstack.push(5);
	// mstack.push(737);
	// mstack.push(0);

	// MutantStack<int>::iterator it = mstack.begin();
	// MutantStack<int>::iterator ite = mstack.end();

	// ++it;
	// --it;
	// while (it != ite)
	// {
	// 	std::cout << *it << std::endl;
	// 	++it;
	// }
	// for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); rit++) {
	// 	std::cout << *rit << std::endl;
	// }
	// std::cout << "---------copy constructor and reverse iterator MutantStack test-------------" << std::endl;
	// MutantStack<int> s(mstack);

	// for (MutantStack<int>::reverse_iterator rit = s.rbegin(); rit != s.rend(); rit++) {
	// 	std::cout << *rit << std::endl;
	// }
	// std::cout << "---------------basic list_test------------------" << std::endl;

	// std::list<int> origin_list;

	// origin_list.push_back(5);
	// origin_list.push_back(17);

	// std::cout << origin_list.front() << std::endl;

	// origin_list.back();

	// std::cout << origin_list.size() << std::endl;

	// std::cout << "--------------main list_test------------------" << std::endl;
	// origin_list.push_back(3);
	// origin_list.push_back(5);
	// origin_list.push_back(737);
	// origin_list.push_back(0);

	// std::list<int>::iterator list_it = origin_list.begin();
	// std::list<int>::iterator list_ite = origin_list.end();

	// ++list_it;
	// --list_it;
	// while (list_it != list_ite)
	// {
	// 	std::cout << *list_it << std::endl;
	// 	++list_it;
	// }
	// std::cout << "---------copy assignment operator and reverse iterator MutantStack test-------------" << std::endl;
	// MutantStack<int> dest;

	// dest = mstack;

	// for (MutantStack<int>::reverse_iterator rit = dest.rbegin(); rit != dest.rend(); rit++) {
	// 	std::cout << *rit << std::endl;
	// }

	// std::cout << "---------copy assignment operator MutantStack test-------------" << std::endl;

	// mstack.push(1);
	// mstack.push(1);
	// mstack.push(1);
	// mstack.push(1);
	// mstack.push(1);

	// for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); it++) {
	// 	std::cout << *it << std::endl;
	// }
	// std::cout << "---------copy assignment operator MutantStack test-------------" << std::endl;

	// mstack = dest;

	// for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); it++) {
	// 	std::cout << *it << std::endl;
	// }
	// return 0;
}