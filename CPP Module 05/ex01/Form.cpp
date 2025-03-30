/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 18:06:02 by octoross          #+#    #+#             */
/*   Updated: 2025/03/30 01:49:48 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void): _name("Default Form"), _signed(false), _signGrade(150), _executeGrade(150) {}
Form::Form(const std::string name, int signGrade, int executeGrade): _name(name), _signed(false)
{
	setSignGrade(signGrade);
	setExecuteGrade(executeGrade);	
}
Form::Form(const Form &to_copy): _name(to_copy._name), _signed(to_copy._signed), _signGrade(to_copy._signGrade), _executeGrade(to_copy._executeGrade) {}
Form &Form::operator= (const Form &to_copy)
{
	if (&to_copy == this)
		return (*this);
	_signed = to_copy._signed;
	_executeGrade = to_copy._executeGrade;
	_signGrade = to_copy._signGrade;
	return (*this);
}
Form::~Form(void) {}

const std::string	Form::getName(void) const { return (_name); }
int 				Form::getSignGrade(void) const { return (_signGrade); }
int 				Form::getExecuteGrade(void) const { return (_executeGrade); }

void	Form::setSignGrade(int grade)
{
	if (grade < 1)
		throw GradeTooLowException();
	else if (grade > 150)
		throw GradeTooHighException();
	else
		_signGrade = grade;
}

void	Form::setExecuteGrade(int grade)
{
	if (grade < 1)
		throw GradeTooLowException();
	else if (grade > 150)
		throw GradeTooHighException();
	else
		_executeGrade = grade;
}

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _signGrade)
		throw GradeTooLowException();
	else
		_signed = true;
}

const char *Form::GradeTooHighException::what(void) const throw() { return ("Form grade too low"); }
const char *Form::GradeTooLowException::what(void) const throw() { return ("Form grade too high"); }
	