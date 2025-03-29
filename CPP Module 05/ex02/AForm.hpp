/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:56:26 by octoross          #+#    #+#             */
/*   Updated: 2025/03/20 19:28:52 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP

# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_signed;
		int					_signGrade;
		int					_executeGrade;
		void	setExecuteGrade(int grade);
		void	setSignGrade(int grade);

	public:
		AForm(void);
		AForm(const std::string name, int signGrade, int executeGrade);
		AForm(const AForm &to_copy);
		AForm &operator= (const AForm &to_copy);
		~AForm(void);

		const std::string	getName(void) const;
		int 				getSignGrade(void) const;
		int 				getExecuteGrade(void) const;
		
		void			beSigned(const Bureaucrat &bureaucrat);
		void			checkExecutionRights(Bureaucrat const &executor) const;
		virtual void	execute(Bureaucrat const &executor) const = 0;

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
		class NotSignedException: public std::exception
		{
			public:
				const char *what(void) const throw();
		};
};

#endif