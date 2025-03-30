/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 16:18:28 by octoross          #+#    #+#             */
/*   Updated: 2025/03/29 20:49:30 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP

# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

# include <dirent.h>
# include <sys/stat.h>
# include <fstream>
# include <cstring>

class ShrubberyCreationForm: public AForm
{
	private:
		std::string _target;

	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &to_copy);
		ShrubberyCreationForm	&operator= (const ShrubberyCreationForm &to_copy);
		~ShrubberyCreationForm(void);
	
		void	execute(Bureaucrat const &executor) const;
};

#endif