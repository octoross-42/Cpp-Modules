/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:43:24 by octoross          #+#    #+#             */
/*   Updated: 2025/03/20 17:52:28 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	try { Bureaucrat	bureaucrat1; }
	catch (std::exception &e) { std::cerr << e.what() << std::endl; }
	
	try { Bureaucrat bureaucrat2 = Bureaucrat("Lala", 15); }
	catch (std::exception &e) { std::cerr << e.what() << std::endl; }

	try { Bureaucrat bureaucrat3 = Bureaucrat("Lala", 0); }
	catch (std::exception &e) { std::cerr << e.what() << std::endl; }
	
	try { Bureaucrat bureaucrat4 = Bureaucrat("Lala", 152); }
	catch (std::exception &e) { std::cerr << e.what() << std::endl; }
	
	return (0);
}
