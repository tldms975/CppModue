#include "MutantStack.hpp"
#include <iostream>
#include <stack>
#include <list>
#include <string>

int main()
{
	{
		std::cout << "-------------TEST1-------------" << std::endl;
		MutantStack<int> mstack;
		mstack.push(1);
		mstack.push(2);
		mstack.push(3);
		mstack.push(4);
		mstack.push(5);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		while (it != ite) {
			std::cout << *it << std::endl;
			++it;
		}
		{
			std::cout << "-------------TEST1(list)-------------" << std::endl;
			std::list <int> mlist;
			mlist.push_back(1);
			mlist.push_back(2);
			mlist.push_back(3);
			mlist.push_back(4);
			mlist.push_back(5);
			std::list<int>::iterator it = mlist.begin();
			std::list<int>::iterator ite = mlist.end();
			while (it != ite)
			{
				std::cout << *it << std::endl;
				// *it = 0;
				++it;
			}
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
			MutantStack<char>::const_iterator it = mstack.begin();
			MutantStack<char>::const_iterator ite = mstack.end();
			++it;
			--it;
			while (it != ite) {
				std::cout << *it << std::endl;
				//*it = 'q';
				++it;
			}
			{
				std::cout << "-------------TEST2(list)-------------" << std::endl;
				std::list <char> mlist;
				mlist.push_back('a');
				mlist.push_back('b');
				mlist.push_back('c');
				mlist.push_back('d');
				mlist.push_back('e');
				std::list<char>::const_iterator it = mlist.begin();
				std::list<char>::const_iterator ite = mlist.end();
				while (it != ite)
				{
					std::cout << *it << std::endl;
					//*it = 'q';
					++it;
				}
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
			while (rit != rite) {
				std::cout << *rit << std::endl;
				++rit;
			}
			{
				std::cout << "-------------TEST3(list)-------------" << std::endl;
				std::list<double> mlist;
				mlist.push_back(1.0);
				mlist.push_back(2.0);
				mlist.push_back(3.0);
				mlist.push_back(4.0);
				mlist.push_back(5.0);
				std::list<double>::reverse_iterator it = mlist.rbegin();
				std::list<double>::reverse_iterator ite = mlist.rend();
				while (it != ite)
				{
					std::cout << *it << std::endl;
					++it;
				}
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
			MutantStack<std::string>::const_reverse_iterator rit = mstack.rbegin();
			MutantStack<std::string>::const_reverse_iterator rite = mstack.rend();
			while (rit != rite) {
				std::cout << *rit << std::endl;
				// *rit = "q";// compile error
				++rit;
			}
			{
				std::cout << "-------------TEST4(list)-------------" << std::endl;
				std::list<std::string> mlist;
				mlist.push_back("a");
				mlist.push_back("b");
				mlist.push_back("c");
				mlist.push_back("d");
				mlist.push_back("e");
				std::list<std::string>::const_reverse_iterator it = mlist.rbegin();
				std::list<std::string>::const_reverse_iterator ite = mlist.rend();
				while (it != ite)
				{
					std::cout << *it << std::endl;
					// *it = "q"; //compile error
					++it;
				}
			}
		}
	}
	return 0;
}