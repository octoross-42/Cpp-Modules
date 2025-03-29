/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:26:28 by octoross          #+#    #+#             */
/*   Updated: 2025/03/29 02:18:42 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP

# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

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

# define BOLD "\x1B[1m"
# define UNDERLINE "\x1B[4m"

# define RESET "\033[0m"

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