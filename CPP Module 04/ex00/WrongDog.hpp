/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:36:14 by octoross          #+#    #+#             */
/*   Updated: 2025/03/19 19:05:08 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGDOG_HPP

# define WRONGDOG_HPP

#include "WrongAnimal.hpp"

class	WrongDog: public WrongAnimal
{
	public:
        WrongDog(void);
		~WrongDog(void);
		
        void    makeSound(void) const;
};

#endif