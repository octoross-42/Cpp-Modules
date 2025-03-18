/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FlagTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 21:03:13 by octoross          #+#    #+#             */
/*   Updated: 2025/03/18 02:07:03 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAPGTRAP_HPP

# define FLAPGTRAP_HPP

# include "ScavTrap.hpp"

class FlagTrap: public virtual ClapTrap
{
	public:
		FlagTrap(void);
		FlagTrap(std::string name);
		~FlagTrap(void);
		
		void	highFivesGuys(void);
};


#endif