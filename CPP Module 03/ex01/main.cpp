/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 16:56:23 by octoross          #+#    #+#             */
/*   Updated: 2025/03/17 20:58:03 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap	p1;
	ScavTrap	p2("Lana");

	int i = 0;
	while (i < 51)
	{
		p1.attack("Lana");
		i ++;
	}

	p2.attack("p1");
	p2.guardGate();

}
