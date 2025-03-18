/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 20:04:43 by octoross          #+#    #+#             */
/*   Updated: 2025/03/18 21:08:53 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void): _type("Default type") {}
AMateria::AMateria(std::string const &type): _type(type) {}
AMateria::AMateria(const AMateria &to_copy): _type(to_copy.getType()) {}
AMateria::~AMateria(void) {}

AMateria    &AMateria::operator= (const AMateria &to_copy)
{
    if (this == &to_copy)
        return (*this);
    _type = to_copy.getType();
    return (*this);
}

std::string const &AMateria::getType() const { return _type; }
