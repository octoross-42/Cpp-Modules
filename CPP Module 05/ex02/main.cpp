/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:43:24 by octoross          #+#    #+#             */
/*   Updated: 2025/03/29 20:50:33 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (0);

	PresidentialPardonForm papageno = PresidentialPardonForm("Papageno");
	Bureaucrat bureaucrat = Bureaucrat("Fatigue", 2);
	ShrubberyCreationForm dot = ShrubberyCreationForm(argv[1]);
	
	bureaucrat.signForm(papageno);
	bureaucrat.signForm(dot);

	try { papageno.execute(bureaucrat); dot.execute(bureaucrat); }
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
