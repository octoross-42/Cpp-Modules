/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 22:12:17 by octoross          #+#    #+#             */
/*   Updated: 2025/03/05 23:51:04 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void) {}
Weapon::~Weapon(void) {}


Weapon::Weapon(std::string type) { _type = type; }
void    Weapon::setType(std::string newType) { _type = newType; }

std::string&  Weapon::getType(void) { return (_type); }