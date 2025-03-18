/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:38:49 by octoross          #+#    #+#             */
/*   Updated: 2025/03/18 17:23:37 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	_brain = new Brain();
	_type = "Dog";
	std::cout << BOLD << GREEN << "Dog" << RESET << " Default constructor has been called" << std::endl;
}

Dog::~Dog(void)
{
	delete _brain;
	std::cout << "Bybye " << BOLD << GREEN << _type << RESET << std::endl;
}

std::string	Dog::getIdea(int i) const
{
	if ((i < 0) || (i > 99))
		return ("");
	return _brain->getIdea(i);
}

void	Dog::makeSound(void) const
{
	std::cout << "Woaf Woaf" << std::endl;
}

Dog::Dog(const Dog &to_copy)
{
	if (&to_copy == this)
		return ;
	_type = to_copy.getType();
	_brain = new Brain();
	int i = 0;
	while (i < 100)
	{
		_brain->setIdea(i, to_copy.getIdea(i));
		i ++;
	}
}

Dog&	Dog::operator= (const Dog &to_copy)
{
	if (&to_copy == this)
		return (*this);
	_type = to_copy.getType();
	_brain = new Brain();
	int i = 0;
	while (i < 100)
	{
		_brain->setIdea(i, to_copy.getIdea(i));
		i ++;
	}
	return (*this);
}

void	Dog::setIdea(int i, std::string idea)
{
	_brain->setIdea(i, idea);
}