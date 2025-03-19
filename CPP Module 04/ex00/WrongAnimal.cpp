/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 16:54:54 by octoross          #+#    #+#             */
/*   Updated: 2025/03/17 18:53:03 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
	_type = "WrongAnimal";
	std::cout << "WrongAnimal Default constructor has been called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type)
{
	_type = type;
	std::cout << "Hello WrongAnimal " << _type << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "Bybye " << BOLD << YELLOW << _type << RESET << std::endl;
}

std::string	WrongAnimal::getType(void) const { return (_type); }

void	WrongAnimal::makeSound(void) const
{
	std::cout << "**WrongAnimal Sounds**" << std::endl;
}
