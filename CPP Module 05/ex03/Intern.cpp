/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 19:55:39 by octoross          #+#    #+#             */
/*   Updated: 2025/03/30 21:04:37 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void) {}
Intern::Intern(const Intern &to_copy) { (void)to_copy; }
Intern &Intern::operator= (const Intern &to_copy) { (void)to_copy; return (*this); }
Intern::~Intern(void) {}

int	indexOf(std::string tab[], int size, std::string to_find)
{
	int i = 0;
	while (i < size)
	{
		if (tab[i] == to_find)
			return (i);
		i ++;
	}
	return (-1);
}

std::string toLowerCase(std::string str)
{
	std::string lower = str;
	int i = 0;
	while (str[i])
	{
		lower[i] = std::tolower(str[i]);
		i ++;
	}
	return (lower);
}

AForm	*Intern::makeForm(std::string form_name, std::string target)
{
	std::string availableForms[] = {"shrubbery creation", "shrubberycreation", "robotomy request", "robotomyrequest", "presidential pardon", "presidentialpardon"};
	int i = indexOf(availableForms, 6, toLowerCase(form_name));
	
	AForm *newForm = NULL;
	switch (i)
	{
		case 0: case 1:
			newForm = new ShrubberyCreationForm(target);
			break;
		case 2: case 3:
			newForm = new RobotomyRequestForm(target);
			break;
		case 4: case 5:
			newForm = new PresidentialPardonForm(target);
			break;
		default:
			std::cout << BOLD << "Intern" << RESET << " couldnt make " << BYELLOW << form_name << RESET " form" << std::endl;
			return (NULL);
	}
	std::cout << BOLD << "Intern" << RESET << " creates " << BYELLOW << form_name << RESET << std::endl;
	return (newForm);
}