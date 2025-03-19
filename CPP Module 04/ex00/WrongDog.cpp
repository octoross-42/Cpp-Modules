/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:38:49 by octoross          #+#    #+#             */
/*   Updated: 2025/03/19 19:10:38 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongDog.hpp"

WrongDog::WrongDog(void): WrongAnimal("WrongDog")
{
	_type = "WrongDog";
	std::cout << "WrongDog Default constructor has been called" << std::endl;
}

WrongDog::~WrongDog(void)
{
	std::cout << "Bybye " << BOLD << YELLOW << _type << RESET << std::endl;
}

void	WrongDog::makeSound(void) const
{
	std::cout << "Wrong Woaf Woaf" << std::endl;
}
