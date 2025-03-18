/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FlagTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 21:04:57 by octoross          #+#    #+#             */
/*   Updated: 2025/03/18 02:58:33 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "FlagTrap.hpp"

FlagTrap::FlagTrap(void)
{
	_hitPoints = 100;
	_eneryPoints = 100;
	_attackDmg = 30;

	std::cout << "FlagTrap Default constructor has been called" << std::endl;
}

FlagTrap::FlagTrap(std::string name) : ClapTrap(name)
{
	_hitPoints = 100;
	_eneryPoints = 100;
	_attackDmg = 30;
	std::cout << "Welcome to FlagTrap: " << BOLD << YELLOW << _name << RESET << "!" << std::endl;
}

FlagTrap::~FlagTrap(void)
{
	std::cout << "Bybye FlagTrap " << BOLD << YELLOW << _name << RESET << std::endl;
}


void	FlagTrap::highFivesGuys(void)
{
	std::cout << "\tFlagTrap " << BOLD << GREEN << _name << RESET << " is requesting a high five (?)!" << std::endl;	
}