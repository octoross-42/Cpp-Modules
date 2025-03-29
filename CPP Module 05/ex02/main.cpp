/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:43:24 by octoross          #+#    #+#             */
/*   Updated: 2025/03/29 03:21:09 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	PresidentialPardonForm papageno = PresidentialPardonForm("Papageno");
	Bureaucrat bureaucrat = Bureaucrat("Fatigue", 42);
	
	bureaucrat.signForm(papageno);

	try { papageno.execute(bureaucrat);}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
