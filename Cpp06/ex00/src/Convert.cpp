#include "Convert.hpp"
#include <iostream>
#include <cmath>
#include <iomanip>

Convert::Convert()
{
}

Convert::Convert(std::string input)
: _input(input)
{
	// this->_c = toChar();
	// this->_i = toInt();
	// this->_f = toFloat();
	// this->_d = toDouble();
}

Convert::Convert(Convert const & o)
{
	this->_input = o._input;
	this->_c = o._c;
	this->_i = o._i;
	this->_f = o._d;
	this->_d = o._d;
}

Convert::~Convert()
{
}

Convert & Convert::operator=(Convert const & o)
{
	if (this == &o)
		return (*this);
	this->_input = o._input;
	this->_c = o._c;
	this->_i = o._i;
	this->_f = o._d;
	this->_d = o._d;
	return *this;
}

void	Convert::setInput(std::string input)
{
	this->_input = input;
}

//convert
char	Convert::toChar()
{
	if (this->_input.length() == 1 && !isdigit(this->_input[0]))
		return (this->_input[0]);
	else if (this->_input.length() == 1 && isdigit(this->_input[0]))
		throw NonDisplayableException();
	else if (this->_input.length() > 1 && !isdigit(this->_input[0]))
		throw ImpossibleException();
	else if (this->_input.length() > 1 && isdigit(this->_input[0]))
	{
		int i = std::stoi(this->_input);
		if (i < 0 || i > 127)
			throw NonDisplayableException();
		else
			return (static_cast<char>(i));
	}
	return (0);
}

int		Convert::toInt()
{
	if (this->_input.length() == 1 && !isdigit(this->_input[0]))
		throw Convert::NonDisplayableException();
	else if (this->_input.length() == 1 && isdigit(this->_input[0]))
		return (std::stoi(this->_input));
	else if (this->_input.length() > 1 && !isdigit(this->_input[0]))
		throw Convert::ImpossibleException();
	else if (this->_input.length() > 1 && isdigit(this->_input[0]))
	{
		int i = std::stoi(this->_input);
		if (i < 0 || i > 127)
			throw Convert::NonDisplayableException();
		else
			return (i);
	}
	return (0);
}

float	Convert::toFloat()
{
	if (this->_input.length() == 1 && !isdigit(this->_input[0]))
		throw std::exception();
	else if (this->_input.length() == 1 && isdigit(this->_input[0]))
		return (std::stof(this->_input));
	else if (this->_input.length() > 1 && !isdigit(this->_input[0]))
		throw std::exception();
	else if (this->_input.length() > 1 && isdigit(this->_input[0]))
	{
		int i = std::stoi(this->_input);
		if (i < 0 || i > 127)
			throw std::exception();
		else
			return (static_cast<float>(i));
	}
	return (0);
}

double	Convert::toDouble()
{
	if (this->_input.length() == 1 && !isdigit(this->_input[0]))
		throw std::exception();
	else if (this->_input.length() == 1 && isdigit(this->_input[0]))
		return (std::stod(this->_input));
	else if (this->_input.length() > 1 && !isdigit(this->_input[0]))
		throw std::exception();
	else if (this->_input.length() > 1 && isdigit(this->_input[0]))
	{
		int i = std::stoi(this->_input);
		if (i < 0 || i > 127)
			throw std::exception();
		else
			return (static_cast<double>(i));
	}
	return (0);
}


//print
void Convert::printChar()
{
	std::cout << "char: ";
	try
	{
		this->_c = toChar();
		std::cout << "'" << this->_c << "'" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void Convert::printInt()
{
	std::cout << "int: ";
	try
	{
		std::cout << this->toInt() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void Convert::printFloat()
{
	std::cout << "float: ";
	try
	{
		std::cout << std::fixed << std::setprecision(1) << this->toFloat() << "f" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << "f\n";
	}
}

void Convert::printDouble()
{
	std::cout << "double: ";
	try
	{
		std::cout << std::fixed << std::setprecision(1) << this->toDouble() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void Convert::printAll()
{
	this->printChar();
	this->printInt();
	this->printFloat();
	this->printDouble();
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

const char * Convert::NotANumberException::what() const throw()
{
	return ("nan");
}

const char * Convert::InfinityException::what() const throw()
{
	return ("inf");
}
