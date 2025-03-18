/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:35:46 by octoross          #+#    #+#             */
/*   Updated: 2025/03/18 17:23:04 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP

# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class	Cat: public Animal
{
	private:
		Brain	*_brain;
	protected:
		std::string	_type;
	public:
        Cat(void);
		~Cat(void);
		Cat(const Cat &to_copy);
		Cat&	operator= (const Cat &to_copy);

		std::string	getIdea(int i) const;
		void    	makeSound(void) const;
		void		setIdea(int i, std::string idea);
};

#endif