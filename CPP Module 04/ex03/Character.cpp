/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 20:35:42 by octoross          #+#    #+#             */
/*   Updated: 2025/03/18 22:05:42 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void)
{
    _name = "Default User";
	_inventory[0] = NULL;
	_inventory[1] = NULL;
	_inventory[2] = NULL;
	_inventory[3] = NULL;
}

Character::Character(std::string name)
{
    _name = name;
	_inventory[0] = NULL;
	_inventory[1] = NULL;
	_inventory[2] = NULL;
	_inventory[3] = NULL;
}

Character::Character(const Character &to_copy)
{
	if (this == &to_copy)
		return ;

    _name = to_copy.getName();
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
		if (to_copy.getMateria(i))
			_inventory[i] = to_copy.getMateria(i)->clone();
		i ++;
	}
}

Character   &Character::operator= (const Character &to_copy)
{
	if (this == &to_copy)
		return (*this);

    _name = to_copy.getName();
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
		if (to_copy.getMateria(i))
			_inventory[i] = to_copy.getMateria(i)->clone();
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
}

std::string const &Character::getName() const { return _name; }

const AMateria    *Character::getMateria(int i) const
{
	if ((i < 0) || (i > 3))
		return (NULL);
	return (_inventory[i]);
}

void Character::equip(AMateria* m)
{
	int i = 0;
	while (i < 4)
	{
		if (!_inventory[i])
		{
			std::cout << YELLOW << BOLD << _name << RESET << "equips " << MAGENTA << BOLD << m->getType() << std::endl;
			_inventory[i] = m;
			break ;
		}
		i ++;
	}
}

void Character::unequip(int idx)
{
	if ((idx < 0) || (idx > 3))
		return ;
	_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if ((idx < 0) || (idx > 3))
		return ;
	if (!_inventory[idx])
		return ;
	std::cout << "use truc" << std::endl;
	_inventory[idx]->use(target);
}