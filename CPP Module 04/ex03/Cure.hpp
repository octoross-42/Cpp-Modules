/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 19:57:55 by octoross          #+#    #+#             */
/*   Updated: 2025/03/19 02:18:40 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP

# define CURE_HPP

# include "AMateria.hpp"

class Cure: public AMateria
{
    public:
        Cure(void);
        Cure(std::string const &type);
        Cure(const Cure &to_copy);
        Cure    &operator= (const Cure &to_copy);
        ~Cure(void);
    
        Cure* clone() const;
        void use(ICharacter& target);
};

#endif