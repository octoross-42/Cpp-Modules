/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:35:46 by octoross          #+#    #+#             */
/*   Updated: 2025/03/18 14:50:23 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP

# define CAT_HPP

#include "Animal.hpp"

class	Cat: public Animal
{
	protected:
		std::string	_type;
	public:
        Cat(void);
		~Cat(void);

		void    makeSound(void) const;
};

#endif