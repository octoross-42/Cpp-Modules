/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 16:56:23 by octoross          #+#    #+#             */
/*   Updated: 2025/03/18 03:04:26 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

std::string	intToString(int n)
{
	std::ostringstream oss;
    oss << n;
	return (oss.str());
}

int	main(void)
{
	DiamondTrap	p1;
	DiamondTrap	p2("Lara");
	
	int i = 0;
	while (i < 51)
	{
		p1.attack("Lara");
		i ++;
	}
	p1.whoAmI();
	p2.whoAmI();
}
