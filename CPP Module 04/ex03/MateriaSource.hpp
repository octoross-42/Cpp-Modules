/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 21:18:50 by octoross          #+#    #+#             */
/*   Updated: 2025/03/19 02:36:42 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIA_SOURCE

# define MATERIA_SOURCE

#include "IMateriaSource.hpp"

class   MateriaSource: public IMateriaSource
{
    private:
        AMateria    *_knowMaterials[4];
        int         _knowMatNbr;

    public:
        MateriaSource(void);
        MateriaSource(const MateriaSource &to_copy);
        MateriaSource   &operator= (const MateriaSource &to_copy);
        virtual ~MateriaSource(void);
    
        int     getNbrKnowMaterials(void) const;
        AMateria    *getCloneMateria(int i) const;
		AMateria	*getMateria(int i);
        void    learnMateria(AMateria *mat);
        AMateria* createMateria(std::string const & type);
};

#endif