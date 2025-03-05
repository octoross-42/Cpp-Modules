/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 22:11:59 by octoross          #+#    #+#             */
/*   Updated: 2025/03/05 23:55:07 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::~HumanA(void) {}

HumanA::HumanA(std::string name, Weapon &weapon) : _weapon(weapon)
{
    _name = name;
}

void    HumanA::attack(void)
{
    std::cout << _name << " attakcs with their ";
    std::cout << _weapon.getType() << std::endl;
}
