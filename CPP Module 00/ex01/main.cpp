/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 23:21:37 by octoross          #+#    #+#             */
/*   Updated: 2025/03/01 23:21:37 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	while (1)
	{
		std::string commandInput;
		std::cout << "Enter a command: ";
		std::cin >> commandInput;
		if (commandInput == "EXIT")
			break;
		else if (commandInput == "ADD")
			std::cout << "ADD" << std::endl;
		else if (commandInput == "SEARCH")
			std::cout << "SEARCH" << std::endl;
		else
			std::cout << "\tInvalid command" << std::endl;
	}
}