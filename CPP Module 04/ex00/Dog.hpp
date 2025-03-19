/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:36:14 by octoross          #+#    #+#             */
/*   Updated: 2025/03/19 19:02:57 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP

# define DOG_HPP

#include "Animal.hpp"

class	Dog: public Animal
{
	public:
        Dog(void);
		~Dog(void);
		Dog(const Dog &to_copy);
		Dog&	operator= (const Dog &to_copy);
		
        void    makeSound(void) const;
};

#endif