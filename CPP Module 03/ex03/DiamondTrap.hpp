/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 21:17:42 by octoross          #+#    #+#             */
/*   Updated: 2025/03/18 03:02:13 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP

# define DIAMONDTRAP_HPP

# include "FlagTrap.hpp"

class DiamondTrap : public FlagTrap, public ScavTrap
{
	private:
		std::string _name;

	public:
		DiamondTrap(void);
		DiamondTrap(std::string name);
		virtual ~DiamondTrap(void);
		using ScavTrap::attack;
	
		void	whoAmI();
};

#endif