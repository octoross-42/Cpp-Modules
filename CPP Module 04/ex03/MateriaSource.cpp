/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 21:40:36 by octoross          #+#    #+#             */
/*   Updated: 2025/03/19 18:27:21 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
    _knowMaterials[0] = NULL;
    _knowMaterials[1] = NULL;
    _knowMaterials[2] = NULL;
    _knowMaterials[3] = NULL;
    _knowMatNbr = 0;
	if (MESSAGES > 1)
		std::cout << "Default MateriaSource Constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &to_copy)
{
    if (&to_copy == this)
        return ;
	
	else if (MESSAGES > 1)
		std::cout << "MateriaSource has been copied" << std::endl;
	_knowMatNbr = to_copy._knowMatNbr;
    int i = 0;
    while (i < _knowMatNbr)
    {
        _knowMaterials[i] = to_copy._knowMaterials[i]->clone();
        i ++;
    }
}

MateriaSource   &MateriaSource::operator= (const MateriaSource &to_copy)
{
    if (&to_copy == this)
        return (*this);
	
	else if (MESSAGES > 1)
		std::cout << "MateriaSource has been atrributed another MateriaSource" << std::endl;
    int i = 0;
    while (i < _knowMatNbr)
        delete _knowMaterials[i ++];
    _knowMatNbr = to_copy._knowMatNbr;
    i = 0;
    while (i < _knowMatNbr)
    {
        _knowMaterials[i] = to_copy._knowMaterials[i]->clone();
        i ++;
    }
    return (*this);
}

MateriaSource::~MateriaSource(void)
{
    int i = 0;
    while (i < _knowMatNbr)
	{
        delete _knowMaterials[i];
		i ++;
	}
	if (MESSAGES > 1)
		std::cout << "Bybye MateriaSource" << std::endl;
}

void    MateriaSource::learnMateria(AMateria *mat)
{
    if (_knowMatNbr >= 4)
    {
		if (MESSAGES > 0)
			std::cout << "\tMateriaSource can't learn any AMateria (" << BOLD << MAGENTA << mat->getType() << RESET << ") anymore " << std::endl;
        return ;
    }
	if (MESSAGES > 0)
		std::cout << "\tMateriaSource has learned " << BOLD << MAGENTA << mat->getType() << RESET << std::endl;
    _knowMaterials[_knowMatNbr ++] = mat;
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
    int i = 0;
    while (i < _knowMatNbr)
    {
        if (_knowMaterials[i]->getType() == type)
		{
			if (MESSAGES > 0)
				std::cout << "\tMateriaSource created " << BOLD << MAGENTA << type << RESET << std::endl;
            return (_knowMaterials[i]->clone());
		}
        i ++;
    }
	if (MESSAGES > 0)
		std::cout << "\tMateriaSource doesn't know any " << BOLD << MAGENTA << type << RESET << " and can't create any" << std::endl;
    return (NULL);
}

AMateria    *MateriaSource::getMateria(int i)
{
    if ((i < 0) || (i > 3))
        return (NULL);

    return (_knowMaterials[i]);
}
