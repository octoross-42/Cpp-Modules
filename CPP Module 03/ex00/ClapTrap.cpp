/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 16:54:54 by octoross          #+#    #+#             */
/*   Updated: 2025/03/07 18:00:46 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	_name = "_";
	_hitPoints = 10;
	_eneryPoints = 10;
	_attackDmg = 0;
	std::cout << "ClapTrap Default constructor has been called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	_name = name;
	_hitPoints = 10;
	_eneryPoints = 10;
	_attackDmg = 0;
	std::cout << "Welcome to: " << BOLD << YELLOW << name << RESET << "!" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Bybye " << BOLD << YELLOW << _name << RESET << std::endl;
}

void	ClapTrap::attack(const std::string &target)
{
	if (_eneryPoints > 0)
	{
		_eneryPoints --;
		std::cout << "\tClapTrap " << BOLD << RED << _name << RESET << " attacks " << BOLD << target << RESET << ", causing " << BOLD << _attackDmg << RESET << " points of damage!" << std::endl;	
	}
	else
		std::cout << "\tClapTrap " << BOLD << RED << _name << RESET << " tries to attack " << BOLD << target << RESET << " but doesn't have enough energy left!" << std::endl;	
		
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	
	std::cout << "\tClapTrap " << BOLD << RED << _name << RESET << " takes " << BOLD << amount << RESET << " amount of damage!" << std::endl;	
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_eneryPoints > 0)
	{
		_eneryPoints --;
		std::cout << "\tClapTrap " << BOLD << CYAN << _name << RESET << " repairs " << BOLD << amount << RESET << " amount of health!" << std::endl;	
	}
	
	else
		std::cout << "\tClapTrap " << BOLD << CYAN << _name << " tries to repair " << BOLD << amount << RESET << " amount of health but doesn't have enough energy left!" << std::endl;
}
