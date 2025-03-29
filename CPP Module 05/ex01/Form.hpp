/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:56:26 by octoross          #+#    #+#             */
/*   Updated: 2025/03/29 01:54:36 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP

# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_signed;
		int					_signGrade;
		int					_executeGrade;
		void	setExecuteGrade(int grade);
		void	setSignGrade(int grade);

	public:
		Form(void);
		Form(const std::string name, int signGrade, int executeGrade);
		Form(const Form &to_copy);
		Form &operator= (const Form &to_copy);
		~Form(void);

		const std::string	getName(void) const;
		int 				getSignGrade(void) const;
		int 				getExecuteGrade(void) const;
		
		void	beSigned(const Bureaucrat &bureaucrat);

		class GradeTooHighException: public std::exception
		{
			public:
				const char *what(void) const throw();
		};
		class GradeTooLowException: public std::exception
		{
			public:
				const char *what(void) const throw();
		};
};

#endif