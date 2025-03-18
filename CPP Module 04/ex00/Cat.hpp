/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:35:46 by octoross          #+#    #+#             */
/*   Updated: 2025/03/18 16:17:25 by octoross         ###   ########.fr       */
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
		Cat(const Cat &to_copy);
		Cat&	operator= (const Cat &to_copy);

		void    makeSound(void) const;
};

#endif