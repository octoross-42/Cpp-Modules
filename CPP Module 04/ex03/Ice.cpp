/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 20:04:43 by octoross          #+#    #+#             */
/*   Updated: 2025/03/18 21:12:56 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void): _type("ice") {}
Ice::Ice(std::string const & type): _type(type) {}
Ice::Ice(const Ice &to_copy): _type(to_copy.getType()) {}
Ice::~Ice(void) {}

Ice    &Ice::operator= (const Ice &to_copy)
{
    if (this == &to_copy)
        return (*this);
    _type = to_copy.getType();
    return (*this);
}

std::string const &Ice::getType() const { return _type; }

Ice* Ice::clone() const
{
    return (new Ice());
}

void    Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << CYAN << target.getName() << RESET << "' *" << std::endl;
}
