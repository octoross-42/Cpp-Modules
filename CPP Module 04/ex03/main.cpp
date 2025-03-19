/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 20:13:41 by octoross          #+#    #+#             */
/*   Updated: 2025/03/19 02:41:14 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int	main(void)
{
	
	ICharacter* me = new Character("me");
	
	AMateria* tmp;
	tmp = new Ice();
	me->equip(tmp);
	tmp = new Cure();
	me->equip(tmp);
	me->unequip(1);
	me->unequip(1);
	delete tmp;
	tmp = new Cure();
	me->equip(tmp);
	tmp = new Cure();
	me->equip(tmp);
	tmp = new Cure();
	me->equip(tmp);
	tmp = new Ice();
	me->equip(tmp);
	AMateria *tmp2 = me->getMateria(3);
	me->unequip(3);
	me->equip(tmp);
	me->printInventory();
	delete tmp2;
	delete me;
	
	
	// IMateriaSource* src = new MateriaSource();
	// src->learnMateria(new Ice());
	// src->learnMateria(new Cure());
	
	// ICharacter* me = new Character("me");
	// AMateria* tmp;
	// tmp = src->createMateria("ice");
	// me->equip(tmp);
	// tmp = src->createMateria("cure");
	// me->equip(tmp);
	
	// ICharacter* bob = new Character("bob");
	// me->use(0, *bob);
	// me->use(1, *bob);
	
	// delete bob;
	// delete me;
	// delete src;
	
	return (0);
}
