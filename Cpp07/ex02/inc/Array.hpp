#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template <typename T>
class Array
{
	private:
		T* _array;
		unsigned int _size;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array& c);
		Array& operator=(const Array& c);
		~Array();

		//
		T& operator[](unsigned int i) const;
		unsigned int size() const;

		class OutOfRangeException : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return ("Out of range");
				}
		};
};

template <typename T>
Array<T>::Array()
: _array(NULL), _size(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	if (n == 0)
	{
		this->_array = NULL;
		this->_size = 0;
	}
	else if (n > 0)
	{
		this->_array = new T[n];
		this->_size = n;
	}
	else
		throw Array::OutOfRangeException();
}

template <typename T>
Array<T>::Array(const Array& c)
: _size(c._size)
{
	if (c._array)
	{
		this->_array = new T[c._size];
		for (unsigned int i = 0; i < c._size; i++)
			this->_array[i] = c._array[i];
	}
	else
		this->_array = NULL;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& c)
{
	if (this == &c)
		return (*this);
	if (_array)
		delete [] _array;
	_array = new T[c._size];
	_size = c._size;
	for (unsigned int i = 0; i < _size; i++)
		_array[i] = c._array[i];
	return (*this);
}

template <typename T>
Array<T>::~Array()
{
	if (_array)
		delete [] _array;
}

template <typename T>
T& Array<T>::operator[](unsigned int i) const
{
	if (i >= _size || i < 0)
		throw OutOfRangeException();
	return (_array[i]);
}

template <typename T>
unsigned int Array<T>::size() const
{
	return (_size);
}

#endif