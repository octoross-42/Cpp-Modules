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

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

class PhoneBook
{
	public :
		PhoneBook();
		addContact();
		searchContact();
	private:
		Contact[8] contacts;
};

#endif