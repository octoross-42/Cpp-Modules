/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:38:26 by octoross          #+#    #+#             */
/*   Updated: 2025/03/18 14:53:29 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	_type = "WrongCat";
	std::cout << "WrongCat Default constructor has been called" << std::endl;
}

WrongCat::~WrongCat(void)
{
	std::cout << "Bybye " << BOLD << YELLOW << _type << RESET << std::endl;
}

void	WrongCat::makeSound(void) const
{
	std::cout << "Wrong Meow" << std::endl;
}
