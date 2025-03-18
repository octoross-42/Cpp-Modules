/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 16:55:08 by octoross          #+#    #+#             */
/*   Updated: 2025/03/17 15:52:27 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP

# define WRONGANIMAL_HPP

#include <iostream>

# define RED "\033[0;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define CYAN "\033[0;36m"
# define MAGENTA "\033[0;35m"

# define BOLD "\x1B[1m"
# define UNDERLINE "\x1B[4m"

# define RESET "\033[0m"

class	WrongAnimal
{
	protected:
		std::string	_type;
	public:
		WrongAnimal(void);
		~WrongAnimal(void);

		std::string	getType(void) const;
		void	makeSound(void) const;
};

#endif