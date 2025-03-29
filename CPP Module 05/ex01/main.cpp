/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:43:24 by octoross          #+#    #+#             */
/*   Updated: 2025/03/28 23:10:50 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat	bureaucrat;
	// grade too high
	try { Form		form1 = Form("blabla", 12, 0); }
	catch (std::exception &e) {std::cerr << e.what() << std::endl; }
	
	// grade too low
	try { Form		form2 = Form("bla", 1255, 0); }
	catch (std::exception &e) {std::cerr << e.what() << std::endl; }
	
	Form form = Form("blabla", 1, 1);
	
	// bureaucrat too low cant sign
	bureaucrat.signForm(form);
	
	// signs
	Bureaucrat bureaucrat2("Lalali", 1);
	bureaucrat2.signForm(form);
	return (0);
}
