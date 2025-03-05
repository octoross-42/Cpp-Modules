/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 23:33:00 by octoross          #+#    #+#             */
/*   Updated: 2025/03/01 23:33:00 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
	public :
		PhoneBook();
		~PhoneBook();
		void		addContact();
		void		search();
	private:
		int			_nbr_Contacts;
		Contact	_contacts[8];
};

#endif