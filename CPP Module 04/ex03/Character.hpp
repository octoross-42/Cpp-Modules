/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 20:23:24 by octoross          #+#    #+#             */
/*   Updated: 2025/03/19 17:44:08 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP

# define CHARACTER_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Character: public ICharacter
{
    private:
        AMateria    *_inventory[4];
        std::string _name;

    public:
        Character(void);
        Character(std::string name);
        Character(const Character &to_copy);
        Character   &operator= (const Character &to_copy);
        ~Character(void);

        std::string const &getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);

		// Only exist for better testing
		void		printInventory(void);
		AMateria	*getMateria(int i);
};

#endif