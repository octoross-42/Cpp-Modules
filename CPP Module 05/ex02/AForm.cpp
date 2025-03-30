/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 18:06:02 by octoross          #+#    #+#             */
/*   Updated: 2025/03/20 19:28:46 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void): _name("Default AForm"), _signed(false), _signGrade(150), _executeGrade(150) {}
AForm::AForm(const std::string name, int signGrade, int executeGrade): _name(name), _signed(false)
{
	setSignGrade(signGrade);
	setExecuteGrade(executeGrade);
}
AForm::AForm(const AForm &to_copy): _name(to_copy._name), _signed(to_copy._signed), _signGrade(to_copy._signGrade), _executeGrade(to_copy._executeGrade) {}
AForm &AForm::operator= (const AForm &to_copy)
{
	if (&to_copy == this)
		return (*this);
	_signed = to_copy._signed;
	_executeGrade = to_copy._executeGrade;
	_signGrade = to_copy._signGrade;
	return (*this);
}
AForm::~AForm(void) {}

const std::string	AForm::getName(void) const { return (_name); }
int 				AForm::getSignGrade(void) const { return (_signGrade); }
int 				AForm::getExecuteGrade(void) const { return (_executeGrade); }

void	AForm::setSignGrade(int grade)
{
	if (grade < 1)
		throw GradeTooLowException();
	else if (grade > 150)
		throw GradeTooHighException();
	else
		_signGrade = grade;
}

void	AForm::setExecuteGrade(int grade)
{
	if (grade < 1)
		throw GradeTooLowException();
	else if (grade > 150)
		throw GradeTooHighException();
	else
		_executeGrade = grade;
}

void	AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _signGrade)
		throw GradeTooLowException();
	else
		_signed = true;
}

void	AForm::checkExecutionRights(Bureaucrat const &executor) const
{
	if (!_signed)
		throw NotSignedException();
	else if (executor.getGrade() > _executeGrade)
		throw GradeTooLowException();
}

const char *AForm::GradeTooHighException::what(void) const throw() { return ("Form grade too low"); }
const char *AForm::GradeTooLowException::what(void) const throw() { return ("Form grade too high"); }
const char *AForm::NotSignedException::what(void) const throw() { return ("Form is not signed"); }
