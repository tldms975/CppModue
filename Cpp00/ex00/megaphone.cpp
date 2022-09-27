#include <iostream>
#include <string>

int	main(int ac, char *av[])
{
	std::string	s;

	if (!av)
		return (0);
	for (int i = 1; i < ac; i++)
	{
		for (int j = 0; j < av[i][j]; j++)
			s += toupper(av[i][j]);
		std::cout << s << '\n';
	}
	return (0);
}
