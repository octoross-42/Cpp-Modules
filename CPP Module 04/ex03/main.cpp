/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 20:13:41 by octoross          #+#    #+#             */
/*   Updated: 2025/03/19 18:43:48 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

void	test_AMateria(void)
{
	// test if AMateria class is abstract -> wont compile
	// AMateria	*a = new AMateria();
	// delete a;
}

void	test_Character(void)
{
	std::cout << std::endl << BOLD << YELLOW << "CHARACTER TEST " << RESET << " //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////" << RESET << std::endl << std::endl;
	
	Character	*me = new Character("me");
	me->equip(new Ice());
	me->equip(new Ice());
	me->equip(new Ice());
	me->equip(new Ice());
	Ice	*ice = new Ice();
	me->equip(ice);
	delete ice;
	me->use(1, *me);
	AMateria *cure = me->getMateria(1);
	me->unequip(1);
	delete cure;
	me->equip(new Cure());
	me->printInventory();
	me->use(1, *me);
	delete me;
	std::cout << std::endl << "/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////" << std::endl << std::endl;
}

void	test_MateriaSource(void)
{
	std::cout << std::endl << BOLD << YELLOW << "MATERIASOURCE TEST " << RESET << " ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////" << RESET << std::endl << std::endl;
	
	MateriaSource	*src = new MateriaSource();
	
	AMateria *mat = src->createMateria("ice");
	src->learnMateria(new Ice());
	src->learnMateria(new Ice());
	src->learnMateria(new Ice());
	src->learnMateria(new Ice());
	AMateria	*cure = new Cure();
	src->learnMateria(cure);
	delete cure;
	mat = src->createMateria("cure");
	mat = src->createMateria("ice");
	delete mat;
	delete src;

	std::cout << std::endl;
	
	src = new MateriaSource();
	mat = src->createMateria("cure");
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	mat = src->createMateria("cure");
	delete mat;
	mat = src->createMateria("ice");
	delete mat;
	delete src;
	std::cout << std::endl << "/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////" << std::endl << std::endl;
}

int	main(void)
{
	test_AMateria();
	test_Character();
	test_MateriaSource();

	std::cout << std::endl << BOLD << RED << "SUBJECT TEST " << RESET << " //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////" << RESET << std::endl << std::endl;
	
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	
	delete bob;
	delete me;
	delete src;
	std::cout << std::endl << "/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////" << std::endl << std::endl;

	return (0);
}
