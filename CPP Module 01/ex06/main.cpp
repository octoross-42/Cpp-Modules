/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 00:02:46 by octoross          #+#    #+#             */
/*   Updated: 2025/03/06 11:30:33 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	harl_level(std::string complaint)
{
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int	i = 0;
	
	while (i < 4)
	{
		if (levels[i] == complaint)
			return (i);
		i ++;
	}
	return (-1);
}

int main(int argc, char **argv)
{
    Harl    harl;
	int		i;
    int 	level = -1;
	
    if (argc > 1)
		level = harl_level(argv[1]);
	i = 0;
	while (i <= level)
	{
		switch(i ++)
		{
			case 0:
				harl.complain("DEBUG");
				break;
			case 1:
				harl.complain("INFO");
				break;
			case 2:
				harl.complain("WARNING");
				break;
			case 3:
				harl.complain("ERROR");
				break;
		}
	}
	if (level < 0)
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    return (0);
}
