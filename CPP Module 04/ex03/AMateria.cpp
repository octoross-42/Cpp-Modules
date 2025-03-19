/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 20:04:43 by octoross          #+#    #+#             */
/*   Updated: 2025/03/19 18:24:36 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void): _type("Default type")
{
	if (MESSAGES > 1)
		std::cout << "Default AMateria Constructor called" << std::endl;
}

AMateria::AMateria(std::string const &type): _type(type)
{
	if (MESSAGES > 1)
		std::cout << "Hello AMateria " << MAGENTA << BOLD << _type << RESET << std::endl;
}

AMateria::AMateria(const AMateria &to_copy): _type(to_copy._type)
{
	if (MESSAGES > 1)
		std::cout << "AMateria " << MAGENTA << BOLD << _type << RESET << " has been copied" << std::endl;
}

AMateria::~AMateria(void)
{
	if (MESSAGES > 1)
		std::cout << "Bybye AMateria " << MAGENTA << BOLD << _type << RESET << std::endl;
}

AMateria    &AMateria::operator= (const AMateria &to_copy)
{
    if (this == &to_copy)
        return (*this);
	
	else if (MESSAGES > 1)
		std::cout << "AMateria " << MAGENTA << BOLD << _type << RESET << " has copied" << MAGENTA << BOLD << to_copy._type << RESET << std::endl;
    _type = to_copy._type;
    return (*this);
}

std::string const &AMateria::getType() const { return _type; }
