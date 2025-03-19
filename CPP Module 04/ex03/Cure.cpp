/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 20:04:43 by octoross          #+#    #+#             */
/*   Updated: 2025/03/19 02:17:19 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void): AMateria("cure") {}
Cure::Cure(std::string const &type): AMateria(type) {}
Cure::Cure(const Cure &to_copy): AMateria(to_copy) {}
Cure::~Cure(void) {}

Cure    &Cure::operator= (const Cure &to_copy)
{
    if (this == &to_copy)
        return (*this);
    _type = to_copy.getType();
    return (*this);
}

Cure* Cure::clone() const
{
    return (new Cure());
}

void    Cure::use(ICharacter& target)
{
    std::cout << "* heal " << GREEN << target.getName() << RESET << "'s wounds *" << std::endl;
}

