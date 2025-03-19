/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 21:40:36 by octoross          #+#    #+#             */
/*   Updated: 2025/03/19 02:39:55 by octoross         ###   ########.fr       */
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
}

MateriaSource::MateriaSource(const MateriaSource &to_copy)
{
    if (&to_copy == this)
        return ;
    int i = 0;
    while (i < _knowMatNbr)
        delete _knowMaterials[i ++];
    _knowMatNbr = to_copy.getNbrKnowMaterials();
    i = 0;
    while (i < _knowMatNbr)
    {
        _knowMaterials[i] = to_copy.getCloneMateria(i);
        i ++;
    }
}

MateriaSource   &MateriaSource::operator= (const MateriaSource &to_copy)
{
    if (&to_copy == this)
        return (*this);
    int i = 0;
    while (i < _knowMatNbr)
        delete _knowMaterials[i ++];
    _knowMatNbr = to_copy.getNbrKnowMaterials();
    i = 0;
    while (i < _knowMatNbr)
    {
        _knowMaterials[i] = to_copy.getCloneMateria(i);
        i ++;
    }
    return (*this);
}

MateriaSource::~MateriaSource(void)
{
    int i = 0;
    while (i < _knowMatNbr)
        delete _knowMaterials[i ++];
}

int     MateriaSource::getNbrKnowMaterials(void) const { return _knowMatNbr; }

AMateria    *MateriaSource::getCloneMateria(int i) const
{
    if ((i < 0) || (i > 3))
		return (NULL);

	if (_knowMaterials[i])
    	return (_knowMaterials[i]->clone());
	return (NULL);
}

AMateria    *MateriaSource::getMateria(int i)
{
    if ((i < 0) || (i > 3))
        return (NULL);

    return (_knowMaterials[i]);
}

void    MateriaSource::learnMateria(AMateria *mat)
{
    if (_knowMatNbr >= 4)
    {
        return ;
    }
    _knowMaterials[_knowMatNbr ++] = mat;
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
    int i = 0;
    while (i < _knowMatNbr)
    {
        if (_knowMaterials[i]->getType() == type)
            return (_knowMaterials[i]->clone());
        i ++;
    }
    return (NULL);
}