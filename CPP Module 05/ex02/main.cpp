/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:43:24 by octoross          #+#    #+#             */
/*   Updated: 2025/03/30 20:03:36 by octoross         ###   ########.fr       */
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

	Bureaucrat b146 = Bureaucrat("Fatigue", 146);
	Bureaucrat b138 = Bureaucrat("Fatigue", 138);
	Bureaucrat b73 = Bureaucrat("Fatigue", 73);
	Bureaucrat b46 = Bureaucrat("Fatigue", 46);
	Bureaucrat b26 = Bureaucrat("Fatigue", 26);
	Bureaucrat b6 = Bureaucrat("Fatigue", 6);
	Bureaucrat b1 = Bureaucrat("Fatigue", 1);
	
	ShrubberyCreationForm dot = ShrubberyCreationForm(argv[1]); // sign 145, exec 137
	RobotomyRequestForm robotomy = RobotomyRequestForm("Blablatada"); // sign 72, exec 45
	PresidentialPardonForm papageno = PresidentialPardonForm("Papageno"); // sign 25, exec 5
	
	b146.signForm(dot);
	b73.executeForm(dot);
	b138.signForm(dot);
	b138.executeForm(dot);
	b73.executeForm(dot);
	std::cout << std::endl << std::endl;

	b73.signForm(robotomy);
	b26.executeForm(robotomy);
	b46.signForm(robotomy);
	b46.executeForm(robotomy);
	b26.executeForm(robotomy);
	std::cout << std::endl << std::endl;

	b26.signForm(papageno);
	b1.executeForm(papageno);
	b6.signForm(papageno);
	b6.executeForm(papageno);
	b1.executeForm(papageno);
	std::cout << std::endl;
	
	return (0);
}
