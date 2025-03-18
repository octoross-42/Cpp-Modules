/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 02:14:06 by octoross          #+#    #+#             */
/*   Updated: 2025/03/18 03:03:07 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

std::string	dfltClapName(int trap_num)
{
	return ("default user " + intToString(trap_num) + " _clap_name");
}

DiamondTrap::DiamondTrap(void) : ClapTrap(dfltClapName(_nbr_traps + 1))
{
	_name = "default user " + intToString(_nbr_traps);
	_hitPoints = FlagTrap::_hitPoints;
	_eneryPoints = ScavTrap::_eneryPoints;
	_attackDmg = FlagTrap::_attackDmg;
	std::cout << "DiamondTrap Default constructor has been called" << std::endl;

}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + " _clap_name")
{
	_name = name;
	_hitPoints = FlagTrap::_hitPoints;
	_eneryPoints = ScavTrap::_eneryPoints;
	_attackDmg = FlagTrap::_attackDmg;
	std::cout << "Diamond Hello " << BOLD << YELLOW << name << RESET << "!" << std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "Bybye DiamondTrap " << BOLD << YELLOW << _name << RESET << std::endl;
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "Me, Diamond that shines bright in the sky is called " << BOLD << YELLOW << _name << RESET << "!" << std::endl;
	std::cout << "\tI also goes by the ClapTrap name of " << BOLD << YELLOW << ClapTrap::_name << RESET << "!" << std::endl;

}
