/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 01:21:52 by octoross          #+#    #+#             */
/*   Updated: 2025/03/04 01:21:52 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
    _firstName = "Paul";
    _lastName = "Personne";
    _nickname = "Default";
    _phoneNumber = "0000000000";
    _darkestSecret = "Default Secret";
    _index = 0;
}

Contact::Contact(std::string firstName, std::string	lastName, std::string	nickname, std::string phoneNumber, std::string darkestSecret, int index)
{
    _firstName = firstName;
    _lastName = lastName;
    _nickname = nickname;
    _phoneNumber = phoneNumber;
    _darkestSecret = darkestSecret;
    _index = index;
}

Contact::~Contact() {}

void    Contact::changeIndex() { _index --; }

int Contact::getIndex() { return _index; }
std::string Contact::getFirstName() { return _firstName; }
std::string Contact::getLastName() { return _lastName; }
std::string Contact::getNickname() { return _nickname; }
