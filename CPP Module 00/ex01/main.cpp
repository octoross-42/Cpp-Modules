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

# include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	phoneBook;

	while (1)
	{
		std::string commandInput;
		std::cout << "Enter a command: ";
		std::cin >> commandInput;
		if (commandInput == "EXIT")
			break ;
		else if (commandInput == "ADD")
			phoneBook.addContact();
		else if (commandInput == "SEARCH")
			phoneBook.search();
		else
			std::cout << "\tInvalid command" << std::endl;
	}
	return (0);
}
