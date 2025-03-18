/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:38:26 by octoross          #+#    #+#             */
/*   Updated: 2025/03/18 17:23:15 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	_brain = new Brain();
	_type = "Cat";
	std::cout << RED << BOLD << "Cat" << RESET << " Default constructor has been called" << std::endl;
}

Cat::~Cat(void)
{
	delete _brain;
	std::cout << "Bybye " << BOLD << RED << _type << RESET << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow" << std::endl;
}

std::string	Cat::getIdea(int i) const
{
	if ((i < 0) || (i > 99))
		return ("");
	return _brain->getIdea(i);
}

Cat::Cat(const Cat &to_copy)
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

Cat&	Cat::operator= (const Cat &to_copy)
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

void	Cat::setIdea(int i, std::string idea)
{
	_brain->setIdea(i, idea);
}