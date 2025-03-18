/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:36:14 by octoross          #+#    #+#             */
/*   Updated: 2025/03/18 16:12:24 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP

# define DOG_HPP

#include "Animal.hpp"

class	Dog: public Animal
{
	protected:
		std::string	_type;
	public:
        Dog(void);
		~Dog(void);
		Dog(const Dog &to_copy);
		Dog&	operator= (const Dog &to_copy);
		
        void    makeSound(void) const;
};

#endif