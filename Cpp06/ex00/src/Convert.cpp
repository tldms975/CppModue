#include "Convert.hpp"
#include <iostream>
#include <cmath>
#include <iomanip>
#include <cctype>
#include <limits>

Convert::Convert()
{
}

Convert::Convert(std::string input)
: _str(input) ,_d(0), _endptr(0)
{
	_d = std::strtod(_str.c_str(), &_endptr);
}

Convert::Convert(Convert const & o)
{
	this->_str = o._str;
	this->_d = o._d;
}

Convert::~Convert()
{
}

Convert & Convert::operator=(Convert const & o)
{
	if (this == &o)
		return (*this);
	this->_str = o._str;
	this->_d = o._d;
	return *this;
}

//static
bool Convert::ft_isinf(double d)
{
	return (d != 0 && d == d / 2);
}

bool Convert::ft_isnan(double d)
{
	return (d != d);
}

bool Convert::ft_isdemical(double d) //true -> 소수 false->정수
{
	return (d - static_cast<int>(d) != 0);
}

//convert
char	Convert::toChar()
{
	if (this->_str.length() == 1)
	{
		if (!std::isdigit(this->_str[0]))
			return (this->_str[0]);
		else
			throw Convert::NonDisplayableException();
	}
	if (!this->_str.length() || ft_isdemical(this->_d)\
	|| (*this->_endptr && strcmp(this->_endptr, "f")) \
	|| this->_d < 0 || this->_d > 127 \
	|| ft_isnan(this->_d) || ft_isinf(this->_d))
		throw Convert::ImpossibleException();
	if (std::isprint(this->_d) == 0)
		throw Convert::NonDisplayableException();
	return static_cast<char>(this->_d);
}

int		Convert::toInt()
{
	if (this->_str.length() == 1)
	{
		if (std::isdigit(this->_str[0]))
			return (static_cast<int>(this->_d));
		else
			return (static_cast<int>(this->_str[0]));
	}
	if (!this->_str.length() || (*this->_endptr && strcmp(this->_endptr, "f")) \
	|| this->_d > std::numeric_limits<int>::max() \
	|| this->_d < std::numeric_limits<int>::min() \
	|| ft_isnan(this->_d) || ft_isinf(this->_d))
		throw Convert::ImpossibleException();
	return static_cast<int>(this->_d);
}

float	Convert::toFloat()
{
	if (this->_str.length() == 1)
	{
		if (std::isdigit(this->_str[0]))
			return (static_cast<float>(this->_d));
		else
			return (static_cast<float>(this->_str[0]));
	}
	if (!this->_str.length() \
	|| (*this->_endptr && (strcmp(this->_endptr, "f") || strcmp(this->_endptr, "inf"))) \
)
		throw Convert::ImpossibleException();
	return static_cast<float>(this->_d);
}

double	Convert::toDouble()
{
	if (this->_str.length() == 1)
	{
		if (std::isdigit(this->_str[0]))
			return (this->_d);
		else
			return (static_cast<double>(this->_str[0]));
	}
	if (!this->_str.length() || (*this->_endptr && strcmp(this->_endptr, "f")))
		throw Convert::ImpossibleException();
	return (this->_d);
}


//print
void Convert::printChar()
{
	char	c;

	try
	{
		c = toChar();
		std::cout << "'" << c << "'" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void Convert::printInt()
{
	int		i;

	try
	{
		i = toInt();
		std::cout << i << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void Convert::printFloat()
{
	float	f;

	try
	{
		f = this->toFloat();

		if (f == static_cast<int>(f))
			std::cout << f << ".0";
		else if (ft_isinf(f))
			std::cout << std::showpos << f;
		else
			std::cout << f;
		std::cout << "f" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void Convert::printDouble()
{
	double	d;

	try
	{
		d = this->toDouble();
		if (d == static_cast<int>(d))
			std::cout << d << ".0" << std::endl;
		else if (ft_isinf(d))
			std::cout << std::showpos << d << std::endl;
		else
			std::cout << d << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

// Exception
const char * Convert::NonDisplayableException::what() const throw()
{
	return ("Non displayable");
}

const char * Convert::ImpossibleException::what() const throw()
{
	return ("impossible");
}

std::ostream& operator<<(std::ostream &o, Convert &convert)
{
	o << "char: ";
	convert.printChar();
	o << "int: ";
	convert.printInt();
	o << "float: ";
	convert.printFloat();
	o << "double: ";
	convert.printDouble();
	return o;
}
