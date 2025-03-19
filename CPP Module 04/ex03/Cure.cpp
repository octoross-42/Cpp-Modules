/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 20:04:43 by octoross          #+#    #+#             */
/*   Updated: 2025/03/19 18:26:23 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void): AMateria("cure")
{
	if (MESSAGES > 1)
		std::cout << "Default Cure Constructor called" << std::endl;
}

Cure::Cure(std::string const &type): AMateria(type)
{
	if (MESSAGES > 1)
		std::cout << "Hello Cure " << BOLD << MAGENTA << _type << RESET << std::endl;
}

Cure::Cure(const Cure &to_copy): AMateria(to_copy)
{
	if (MESSAGES > 1)
		std::cout << "Cure " << BOLD << MAGENTA << _type << RESET << " has been copied" << std::endl;
}

Cure::~Cure(void)
{
	if (MESSAGES > 1)
		std::cout << "Bybye Cure " << BOLD << MAGENTA << _type << RESET << std::endl;
}

Cure    &Cure::operator= (const Cure &to_copy)
{
    if (this == &to_copy)
        return (*this);
	
	else if (MESSAGES > 1)
		std::cout << "Cure " << BOLD << MAGENTA << _type << RESET << " copied " << BOLD << MAGENTA << to_copy._type << std::endl;
    _type = to_copy._type;
    return (*this);
}

Cure* Cure::clone() const
{
    return (new Cure());
}

void    Cure::use(ICharacter& target)
{
	if (MESSAGES > 1)
		std::cout << "\t";
    std::cout << "* heal " << GREEN << target.getName() << RESET << "'s wounds *" << std::endl;
}

