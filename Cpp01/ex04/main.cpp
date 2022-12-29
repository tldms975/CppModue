#include <iostream>
#include <string>
#include <fstream>

void ft_replace(std::ifstream &in, std::ofstream &out, std::string s1, std::string s2)
{
	std::string::size_type	spot;
	std::string	bufLine;
	bool	flag;

	while (!in.eof())
	{
		std::getline(in, bufLine);
		spot = 0;
		flag = 0;
		while ((spot = bufLine.find(s1)) != std::string::npos)
		{
			flag = 1;
			out << bufLine.substr(0, spot) << s2 << (bufLine = bufLine.substr(spot + s1.length()));
		}
		if (!flag)
			out << bufLine;
		out << "\n";
	}
}

bool checkValid(int ac, char *av[])
{
	if (ac == 4 && av[1] && av[2] && av[3])
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

		if (in.is_open())
		{
			if (out.is_open())
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