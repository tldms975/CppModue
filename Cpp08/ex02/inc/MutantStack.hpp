#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack();
		MutantStack(const MutantStack& ms);
		MutantStack& operator=(const MutantStack& ms);
		~MutantStack();
		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin();
		iterator end();
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		const_iterator begin() const;
		const_iterator end() const;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		reverse_iterator rbegin();
		reverse_iterator rend();
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
		const_reverse_iterator rbegin() const;
		const_reverse_iterator rend() const;

};

template <typename T>
MutantStack<T>::MutantStack()
{
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& ms)
{
	this->c = ms.c;
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& ms)
{
	if (this == &ms)
		return (*this);
	this->c = ms.c;
	return (*this);
}

template <typename T>
MutantStack<T>::~MutantStack()
{
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return (this->c.end());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
	return (MutantStack<T>::c.begin());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const
{
	return (MutantStack<T>::c.end());
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin()
{
	return (this->c.rbegin());
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend()
{
	return (this->c.rend());
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rbegin() const
{
	return (MutantStack<T>::c.rbegin());
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rend() const
{
	return (MutantStack<T>::c.rend());
}

#endif