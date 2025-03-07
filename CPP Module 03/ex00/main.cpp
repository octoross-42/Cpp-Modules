/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 16:56:23 by octoross          #+#    #+#             */
/*   Updated: 2025/03/07 17:59:16 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	p1;
	ClapTrap	p2("Lana");

	p1.attack("Lana");
	p2.takeDamage(5);
	p2.takeDamage(4);
	p2.beRepaired(15);
	p1.attack("Lana");
	p1.attack("Lana");
	p1.attack("Lana");
	p1.attack("Lana");
	p1.attack("Lana");
	p1.attack("Lana");
	p1.attack("Lana");
	p1.attack("Lana");
	p1.attack("Lana");
	p1.attack("Lana");
	p2.attack("_");
}
