/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 01:44:44 by octoross          #+#    #+#             */
/*   Updated: 2025/03/30 20:49:44 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void): AForm("Presidential Pardon Form", 25, 5), _target("unknow") {}
PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("Presidential Pardon Form", 25, 5), _target(target) {}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &to_copy): AForm(to_copy), _target(to_copy._target) {}
PresidentialPardonForm &PresidentialPardonForm::operator= (const PresidentialPardonForm &to_copy)
{
	if (&to_copy == this)
		return (*this);
	AForm::operator=(to_copy);
	_target = to_copy._target;
	return (*this);
}
PresidentialPardonForm::~PresidentialPardonForm(void) {}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
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