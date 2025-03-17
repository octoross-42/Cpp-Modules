/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 16:56:23 by octoross          #+#    #+#             */
/*   Updated: 2025/03/17 21:13:23 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FlagTrap.hpp"

int	main(void)
{
	FlagTrap	p1;
	FlagTrap	p2("Lana");

	int i = 0;
	while (i < 101)
	{
		p1.attack("Lana");
		i ++;
	}

	p2.attack("p1");
	p2.highFivesGuys();

}
