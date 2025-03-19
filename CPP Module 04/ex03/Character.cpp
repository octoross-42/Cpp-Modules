/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 20:35:42 by octoross          #+#    #+#             */
/*   Updated: 2025/03/19 18:25:17 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void)
{
	if (MESSAGES > 1)
		std::cout << "Default Character Constructor called" << std::endl;
	_name = "Default User";
	_inventory[0] = NULL;
	_inventory[1] = NULL;
	_inventory[2] = NULL;
	_inventory[3] = NULL;
}

Character::Character(std::string name)
{
    _name = name;
	if (MESSAGES > 1)
		std::cout << "Hello Character " << YELLOW << BOLD << _name << RESET << "!" << std::endl;
	_inventory[0] = NULL;
	_inventory[1] = NULL;
	_inventory[2] = NULL;
	_inventory[3] = NULL;
}

Character::Character(const Character &to_copy)
{
	if (this == &to_copy)
		return ;
	
	if (MESSAGES > 1)
		std::cout << YELLOW << BOLD << to_copy._name << RESET << " has beed copied" << RESET << std::endl;
    _name = to_copy._name;
	int i = 0;
	while (i < 4)
	{
		_inventory[i] = to_copy._inventory[i]->clone();
		i ++;
	}
}

Character   &Character::operator= (const Character &to_copy)
{
	if (this == &to_copy)
		return (*this);
		
	if (MESSAGES > 1)
		std::cout << YELLOW << BOLD << _name << RESET << " has copied " << YELLOW << BOLD << to_copy._name << RESET << std::endl;
    _name = to_copy._name;
	int i = 0;
	while (i < 4)
	{
		if (_inventory[i])
			delete _inventory[i];
		i ++;
	}
	i = 0;
	while (i < 4)
	{
		_inventory[i] = to_copy._inventory[i]->clone();
		i ++;
	}
	return (*this);
}

Character::~Character(void)
{
	int i = 0;
	while (i < 4)
	{
		if (_inventory[i])
			delete _inventory[i];
		i ++;
	}
	if (MESSAGES > 1)
		std::cout << "Bybye Character " << YELLOW << BOLD << _name << RESET << "!" << std::endl;
}

std::string const &Character::getName() const { return _name; }

void Character::equip(AMateria* m)
{
	int i = 0;
	while (i < 4)
	{
		if (!_inventory[i])
		{
			if (MESSAGES > 0)
				std::cout << "\t" << YELLOW << BOLD << _name << RESET << " equips " << MAGENTA << BOLD << m->getType() << RESET << std::endl;
			_inventory[i] = m;
			return ;
		}
		i ++;
	}
	if (MESSAGES > 0)
		std::cout << "\t" << YELLOW << BOLD << _name << RESET << " has no space room in inventor, cannot equip " << MAGENTA << BOLD << m->getType() << RESET << std::endl;
}

void Character::unequip(int idx)
{
	if ((idx < 0) || (idx > 3))
		return ;
	if (_inventory[idx])
	{
		if (MESSAGES > 0)
			std::cout << "\t" << YELLOW << BOLD << _name << RESET << " has unequiped inventory " << BOLD << "[" << idx << "]" << RESET << ": " << MAGENTA << BOLD << _inventory[idx]->getType() << RESET << std::endl;
		_inventory[idx] = NULL;
	}
	else if (MESSAGES > 0)
		std::cout << "\t" YELLOW << BOLD << _name << RESET << " has empty inventory at index " << BOLD << idx << RESET << ": cannot unequip" << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
	if ((idx < 0) || (idx > 3))
		return ;
	if (!_inventory[idx])
	{
		if (MESSAGES > 0)
			std::cout << "\t" YELLOW << BOLD << _name << RESET << " has empty inventory at index " << BOLD << idx << RESET << ": cannot use" << std::endl;
		return ;
	}
	_inventory[idx]->use(target);
}

void	Character::printInventory(void)
{
	std::cout << "Inventory of " << YELLOW << BOLD << _name << RESET << ":" << std::endl;
	int i = 0;
	bool	empty = true;
	while (i < 4)
	{
		if (_inventory[i])
		{
			std::cout << "\t" << i << " " << BOLD << MAGENTA << _inventory[i]->getType() << RESET << std::endl;
			empty = false;
		}
		i ++;
	}
	if (empty)
		std::cout << "\t(empty)" << std::endl;
}

AMateria	*Character::getMateria(int i)
{
	if ((i < 0) || (i > 3))
		return (NULL);
	return (_inventory[i]);
}