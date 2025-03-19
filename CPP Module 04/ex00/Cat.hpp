/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:35:46 by octoross          #+#    #+#             */
/*   Updated: 2025/03/19 19:02:53 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP

# define CAT_HPP

#include "Animal.hpp"

class	Cat: public Animal
{
	public:
        Cat(void);
		~Cat(void);
		Cat(const Cat &to_copy);
		Cat&	operator= (const Cat &to_copy);

		void    makeSound(void) const;
};

#endif