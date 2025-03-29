/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:27:10 by octoross          #+#    #+#             */
/*   Updated: 2025/03/29 02:20:36 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void): _name("Default Bureaucrat"), _grade(150) {}
Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name) { setGrade(grade); }
Bureaucrat::Bureaucrat(const Bureaucrat &to_copy): _name(to_copy._name), _grade(to_copy._grade) {}
Bureaucrat &Bureaucrat::operator= (const Bureaucrat &to_copy)
{
	if (&to_copy == this)
		return (*this);
	_grade = to_copy._grade;
	return (*this);
}
Bureaucrat::~Bureaucrat(void) {}

const std::string Bureaucrat::getName(void) const { return (_name); }
int Bureaucrat::getGrade(void) const { return (_grade); }

void	Bureaucrat::setGrade(int newGrade)
{
	if (newGrade < 1)
		throw GradeTooHighException();
	else if (newGrade > 150)
		throw GradeTooLowException();
	else
		_grade = newGrade;
}

void	Bureaucrat::incrementGrade(void) { setGrade(_grade - 1); }
void	Bureaucrat::decrementGrade(void) { setGrade(_grade + 1); }
		
const char *Bureaucrat::GradeTooHighException::what(void) const throw() { return ("Bureaucrat grade too high"); }
const char *Bureaucrat::GradeTooLowException::what(void) const throw() { return ("Bureaucrat grade too low"); }
				
std::ostream &operator<<(std::ostream &output, Bureaucrat const &bureaucrat)
{
	output << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (output);
}
