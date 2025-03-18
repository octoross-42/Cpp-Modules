/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:38:26 by octoross          #+#    #+#             */
/*   Updated: 2025/03/18 14:46:09 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	_type = "Cat";
	std::cout << "Cat Default constructor has been called" << std::endl;
}

Cat::~Cat(void)
{
	std::cout << "Bybye " << BOLD << YELLOW << _type << RESET << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow" << std::endl;
}
