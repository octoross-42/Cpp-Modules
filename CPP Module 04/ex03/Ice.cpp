/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 20:04:43 by octoross          #+#    #+#             */
/*   Updated: 2025/03/19 18:31:09 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void): AMateria("ice")
{
	if (MESSAGES > 1)
		std::cout << "Default Ice Constructor called" << std::endl;
}

Ice::Ice(std::string const &type): AMateria(type)
{
	if (MESSAGES > 1)
		std::cout << "Hello Ice " << BOLD << MAGENTA << _type << RESET << std::endl;
}

Ice::Ice(const Ice &to_copy): AMateria(to_copy)
{
	if (MESSAGES > 1)
		std::cout << "Ice " << BOLD << MAGENTA << _type << RESET << " has been copied" << std::endl;
}

Ice::~Ice(void)
{
	if (MESSAGES > 1)
		std::cout << "Bybye Ice " << BOLD << MAGENTA << _type << RESET << std::endl;
}

Ice    &Ice::operator= (const Ice &to_copy)
{
    if (this == &to_copy)
        return (*this);
	
	else if (MESSAGES > 1)
		std::cout << "Ice " << BOLD << MAGENTA << _type << RESET << " copied " << BOLD << MAGENTA << to_copy._type << std::endl;
    _type = to_copy._type;
    return (*this);
}

Ice* Ice::clone() const
{
    return (new Ice());
}

void    Ice::use(ICharacter& target)
{
	if (MESSAGES > 1)
		std::cout << "\t";
    std::cout << "* shoots an ice bolt at " << CYAN << target.getName() << RESET << " *" << std::endl;
}
