#include <iostream>
#include <fstream> // file open
#include <string> // getline
#include "BitcoinExchange.hpp"
#include "utils.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::ifstream database("data.csv");
	if (!database.is_open())
		throw std::runtime_error("Failed to open database.csv");
	std::string line;
	std::getline(database, line); // skip first line
	while (std::getline(database, line))
	{
		std::string	date = line.substr(0, line.find(','));
		std::string	rate = line.substr(line.find(',') + 1);
		char		*endptr;
		float		rate_float = std::strtod(rate.c_str(), &endptr);
		try
		{
			if ((rate_float == 0.0f && rate != "0" && rate != "0.0") \
			|| *endptr)
				throw NotAValidNumberException();
			_data.insert(std::pair <std::string, float>(date, rate_float));
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	if (_data.empty())
		throw EmptyDataException();
	database.close();
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &ref)
{
	*this = ref;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &ref)
{
	if (this == &ref)
		return (*this);
	return (*this);
}

void	BitcoinExchange::run(std::string input)
{
	try
	{
		std::string			date = input.substr(0, input.find('|') - 1);
		std::string			value = input.substr(input.find('|') + 2);
		char				*endptr;
		float value_float = std::strtod(value.c_str(), &endptr);

		// check if the entire input was converted to float
		if ((value_float == 0.0f && value != "0" && value != "0.0") \
		|| *endptr)
			throw NotAValidNumberException();
		else if (value_float < 0)
			throw NegativeNumberException();
		else if (value_float > 1000)
			throw NumberTooLargeException();
		printResult(date, value_float);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void BitcoinExchange::printResult(std::string date, float value)
{
	std::map<std::string, float>::iterator it = _data.begin();
	std::map<std::string, float>::iterator end = _data.end();

	try
	{
		if (date < it->first)
			throw NotAValidDateException();
		std::map<std::string, float>::iterator tmp = it;
		while (it != end && it->first <= date)
		{
			tmp = it;
			++it;
		}
		std::cout << date << " => " << value << " = " << tmp->second * value << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << " => " << date << std::endl;
	}
}
