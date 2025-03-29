/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:43:24 by octoross          #+#    #+#             */
/*   Updated: 2025/03/29 21:13:26 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (0);

	Bureaucrat bureaucrat = Bureaucrat("Fatigue", 2);
	PresidentialPardonForm papageno = PresidentialPardonForm("Papageno");
	ShrubberyCreationForm dot = ShrubberyCreationForm(argv[1]);
	RobotomyRequestForm robotomy = RobotomyRequestForm("Blablatada");
	
	bureaucrat.signForm(papageno);
	bureaucrat.signForm(dot);
	bureaucrat.signForm(robotomy);
	try { papageno.execute(bureaucrat); dot.execute(bureaucrat); robotomy.execute(bureaucrat); }
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
