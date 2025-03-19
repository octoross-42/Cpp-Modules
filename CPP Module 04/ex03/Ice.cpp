/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 20:04:43 by octoross          #+#    #+#             */
/*   Updated: 2025/03/19 02:19:31 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"


Ice::Ice(void): AMateria("ice") {}
Ice::Ice(std::string const &type): AMateria(type) {}
Ice::Ice(const Ice &to_copy): AMateria(to_copy) {}
Ice::~Ice(void) {}

Ice    &Ice::operator= (const Ice &to_copy)
{
    if (this == &to_copy)
        return (*this);
    _type = to_copy.getType();
    return (*this);
}

Ice* Ice::clone() const
{
    return (new Ice());
}

void    Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << CYAN << target.getName() << RESET << "' *" << std::endl;
}
