/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:38:49 by octoross          #+#    #+#             */
/*   Updated: 2025/03/19 19:10:00 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void): Animal("Dog")
{
	std::cout << "Dog Default constructor has been called" << std::endl;
}

Dog::~Dog(void)
{
	std::cout << "Bybye " << BOLD << YELLOW << _type << RESET << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << "Woaf Woaf" << std::endl;
}

Dog::Dog(const Dog &to_copy): Animal(to_copy._type) {}

Dog&	Dog::operator= (const Dog &to_copy)
{
	if (this == &to_copy)
		return (*this);
	_type = to_copy._type;
	return *this;
}
