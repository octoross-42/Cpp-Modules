/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 22:11:57 by octoross          #+#    #+#             */
/*   Updated: 2025/03/05 22:58:04 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::~HumanB(void) {}

HumanB::HumanB(std::string name) { _name = name; _weapon = NULL;}

void    HumanB::setWeapon(Weapon &weapon) { _weapon = &weapon; }

void    HumanB::attack(void)
{
    std::cout << _name << " attakcs with their ";
    std::cout << _weapon->getType() << std::endl;
}
