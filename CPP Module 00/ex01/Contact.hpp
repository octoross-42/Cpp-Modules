/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 23:35:45 by octoross          #+#    #+#             */
/*   Updated: 2025/03/01 23:35:45 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact
{
	public:
		Contact();
		~Contact();
		Contact(std::string firstName, std::string	lastName, std::string	nickname, std::string phoneNumber, std::string darkestSecret, int index);
		void	changeIndex();
		int	getIndex();
		std::string	getFirstName();
		std::string	getLastName();
		std::string	getNickname();
	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickname;
		std::string _phoneNumber;
		std::string _darkestSecret;
		int			_index;
};

#endif