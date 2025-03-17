/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 20:04:40 by octoross          #+#    #+#             */
/*   Updated: 2025/03/17 20:56:45 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	_hitPoints = 100;
	_eneryPoints = 50;
	_attackDmg = 20;

	std::cout << "ScavTrap Default constructor has been called" << std::endl;
}


ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_hitPoints = 100;
	_eneryPoints = 50;
	_attackDmg = 20;
	std::cout << "Welcome to ScavTrap: " << BOLD << YELLOW << name << RESET << "!" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "Bybye ScavTrap " << BOLD << YELLOW << _name << RESET << std::endl;
}

void	ScavTrap::attack(const std::string &target)
{
	if (_eneryPoints > 0)
	{
		_eneryPoints --;
		std::cout << "\tScavTrap " << BOLD << RED << _name << RESET << " attacks " << BOLD << target << RESET << ", causing " << BOLD << _attackDmg << RESET << " points of damage!" << std::endl;	
	}
	else
		std::cout << "\tScavTrap " << BOLD << RED << _name << RESET << " tries to attack " << BOLD << target << RESET << " but doesn't have enough energy left!" << std::endl;	
		
}


void	ScavTrap::guardGate(void)
{
	std::cout << "\tScavTrap " << BOLD << GREEN << _name << RESET << " is now in guard mode!" << std::endl;	
}