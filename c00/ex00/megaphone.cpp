/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasong <jasong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 09:37:22 by jasong            #+#    #+#             */
/*   Updated: 2022/09/03 04:33:20 by jasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

void	printUppercase(std::string s)
{
	int	i;

	i = -1;
	while (s[++i])
		s[i] = std::toupper(s[i]);
	std::cout << s;
}

int	main(int ac, char *av[])
{
	int	i;

	if (ac <= 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		i = 0;
		while (++i < ac)
			printUppercase(av[i]);
		std::cout << std::endl;
	}
	return (0);
}