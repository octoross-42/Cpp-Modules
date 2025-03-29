/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:26:28 by octoross          #+#    #+#             */
/*   Updated: 2025/03/29 18:58:31 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP

# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

# define RED "\033[0;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define CYAN "\033[0;36m"
# define MAGENTA "\033[0;35m"

# define BRED "\x1B[1m\033[0;31m"
# define BGREEN "\x1B[1m\033[1;32m"
# define BYELLOW "\x1B[1m\033[1;33m"
# define BCYAN "\x1B[1m\033[0;36m"
# define BMAGENTA "\x1B[1m\033[0;35m"

# define BGBLACK "\033[40m"   // Black background
# define BGRED "\033[41m"   // Red background
# define BGGREEN "\033[42m"   // Green background
# define BGYELLOW "\033[43m"   // Yellow background
# define BGBLUE "\033[44m"   // Blue background
# define BGMAGENTA "\033[45m"   // Magenta background
# define BGCYAN "\033[46m"   // Cyan background
# define BGWHITE "\033[47m"   // White background

# define BOLD "\x1B[1m"
# define UNDERLINE "\x1B[4m"

# define RESET "\033[0m"

class AForm;

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;
		void				setGrade(int newGrade);
		public:
			Bureaucrat(void);
			Bureaucrat(const std::string name, int grade);
			Bureaucrat(const Bureaucrat &to_copy);
			Bureaucrat &operator= (const Bureaucrat &to_copy);
			~Bureaucrat(void);

			const std::string getName(void) const;
			int getGrade(void) const;

		void	incrementGrade(void);
		void	decrementGrade(void);
		
		void	signForm(AForm &form) const;
		void	executeForm(AForm const & form);
		
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

std::ostream &operator<<(std::ostream &output, Bureaucrat const &bureaucrat);

#endif