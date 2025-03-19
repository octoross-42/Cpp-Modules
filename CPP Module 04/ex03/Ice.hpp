/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 19:57:55 by octoross          #+#    #+#             */
/*   Updated: 2025/03/18 20:11:48 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP

# define ICE_HPP

# include "AMateria.hpp"

class Ice: public AMateria
{
    public:
        Ice(void);
        Ice(std::string const &type);
        Ice(const Ice &to_copy);
        Ice    &operator= (const Ice &to_copy);
        ~Ice(void);
    
        Ice* clone() const;
        void use(ICharacter& target);
};

#endif