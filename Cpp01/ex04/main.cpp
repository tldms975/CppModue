#include <iostream>
#include <string>
#include <fstream>

void ft_replace(std::ifstream &in, std::ofstream &out, std::string s1, std::string s2)
{
	std::string::size_type	spot;
	std::string	bufLine;

	while (std::getline(in, bufLine))
	{
		while ((spot = bufLine.find(s1)) != std::string::npos)
		{
			if (spot)
				out << bufLine.substr(0, spot);
			out << s2;
			bufLine = bufLine.substr(spot + s1.length());
		}
		out << bufLine;
		if (in.good())
			out << "\n";
	}
}

bool checkValid(int ac, char *av[])
{
	std::string	s1 = av[2];
	if (ac == 4 && av[1] && (!s1.empty()) && av[3])
		return (true);
	else
		std::cerr << "Error: Invalid Arguments\n";
	return (false);
}

int	main(int ac, char *av[])
{
	if (checkValid(ac, av))
	{
		std::string	fileName = av[1];
		std::string	s1 = av[2];
		std::string	s2 = av[3];
		std::ifstream in(fileName);
		std::ofstream out(fileName + ".replace");

		if (in.is_open() && in.good())
		{
			if (out.is_open() && out.good())
			{
				ft_replace(in, out, s1, s2);
				in.close();
				out.close();
				return (0);
			}
			else
				in.close();
		}
		std::cerr << "Error: Invalid File\n";
	}
	return (1);
}