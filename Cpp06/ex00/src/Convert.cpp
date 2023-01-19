#include "Convert.hpp"

Convert::Convert()
{
}

Convert::Convert(std::string input)
: _input(input)
{
}

Convert::Convert(Convert const & o)
{
}

Convert::~Convert()
{
}

Convert & Convert::operator=(Convert const & o)
{
	if (this == &o)
		return (*this);
	return *this;
}