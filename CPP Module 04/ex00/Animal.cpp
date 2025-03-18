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

#include "Animal.hpp"

Animal::Animal(void)
{
	_type = "Animal";
	std::cout << "Animal Default constructor has been called" << std::endl;
}

Animal::~Animal(void)
{
	std::cout << "Bybye " << BOLD << YELLOW << _type << RESET << std::endl;
}

std::string	Animal::getType(void) const { return (_type); }

void	Animal::makeSound(void) const
{
	std::cout << "**Animal Sounds**" << std::endl;
}
