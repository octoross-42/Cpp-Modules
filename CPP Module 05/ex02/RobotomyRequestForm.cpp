/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 16:18:22 by octoross          #+#    #+#             */
/*   Updated: 2025/03/29 17:52:38 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void): AForm("Robotomy Request Form", 25, 5), _target("unknow") {}
RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("Robotomy Request Form", 25, 5), _target(target) {}
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
		std::cout << "Target " << BMAGENTA << _target << RESET << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	}
	catch (std::exception &e)
	{
		throw ;
	}
}