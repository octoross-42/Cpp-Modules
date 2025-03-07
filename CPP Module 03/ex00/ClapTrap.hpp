/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 16:55:08 by octoross          #+#    #+#             */
/*   Updated: 2025/03/07 17:51:56 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP

# define CLAPTRAP_HPP

#include <iostream>

# define RED "\033[0;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define CYAN "\033[0;36m"
# define MAGENTA "\033[0;35m"

# define BOLD "\x1B[1m"
# define UNDERLINE "\x1B[4m"

# define RESET "\033[0m"

class	ClapTrap
{
	private:
		std::string	_name;
		int	_eneryPoints;
		int	_attackDmg;
	public:
		int	_hitPoints;
		ClapTrap(void);
		ClapTrap(std::string name);
		~ClapTrap(void);
		
		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		
};

#endif