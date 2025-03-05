/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 22:00:01 by octoross          #+#    #+#             */
/*   Updated: 2025/03/05 22:08:50 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string	brain = "HI THIS IS BRAIN";
	std::string *stringPTR = &brain;
	std::string &stringREF = brain;
	std::cout << "Memory address:" << std::endl;
	std::cout << "\tBrain: " << &brain << std::endl;
	std::cout << "\tPointer on Brain: " << stringPTR << std::endl;
	std::cout << "\tReference on Brain: " << &stringREF << std::endl;
	std::cout << "Values:" << std::endl;
	std::cout << "\tBrain: " << brain << std::endl;
	std::cout << "\tPointer on Brain: " << *stringPTR << std::endl;
	std::cout << "\tReference on Brain: " << stringREF << std::endl;
}
