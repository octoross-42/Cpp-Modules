/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 16:18:22 by octoross          #+#    #+#             */
/*   Updated: 2025/03/29 21:19:21 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void): AForm("Robotomy Request Form", 72, 45), _target("unknow") {}
RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("Robotomy Request Form", 72, 45), _target(target) {}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &to_copy): AForm(to_copy), _target(to_copy._target) {}
RobotomyRequestForm &RobotomyRequestForm::operator= (const RobotomyRequestForm &to_copy)
{
	if (&to_copy == this)
		return (*this);
	AForm::operator=(to_copy);
	_target = to_copy._target;
	return (*this);
}
RobotomyRequestForm::~RobotomyRequestForm(void) {}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	try
	{
		checkExecutionRights(executor);
		srand(time(0));
		int n = rand() % 3;
		if (n == 1)
			std::cout << "Drrrrrrrrrrrrrrrrrrrrrrrrrrr DUM !" << std::endl << "Congrats ! " << BOLD << _target << RESET << " has been successfully robotomized" << std::endl;
		else
			std::cout << "Sorry " << BOLD << _target << RESET << ", your robotomy failed" << std::endl;
	}
	catch (std::exception &e)
	{
		throw ;
	}
}