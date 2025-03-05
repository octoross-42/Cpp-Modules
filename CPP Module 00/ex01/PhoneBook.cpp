/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 01:21:56 by octoross          #+#    #+#             */
/*   Updated: 2025/03/04 01:21:56 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include<unistd.h>

PhoneBook::PhoneBook() {
    _nbr_Contacts = 0;
}
PhoneBook::~PhoneBook() {}

std::string    getUserInput(std::string prompt)
{
    std::string input;

    input = "";
    while (input.length() == 0)
    {
        std::cout << "\t" << prompt << " : ";
        std::getline(std::cin, input);
    }
    return (input);
}

void    PhoneBook::addContact()
{
    int     i;

    std::cin.ignore();
    std::string firstName = getUserInput("First Name");
    std::string lastName = getUserInput("Last Name");
    std::string nickname = getUserInput("Nickname baby");
    std::string phoneNumber = getUserInput("Your very personnal phone number");
    std::string darkestSecret = getUserInput("Your very personal darkest secret");
    if (_nbr_Contacts >= 8)
    {
        i = 0;
        while (i < 7)
        {
            _contacts[i] = _contacts[i + 1];
            _contacts[i].changeIndex();
            i ++;
        }
        _contacts[7] = Contact(firstName, lastName, nickname, phoneNumber, darkestSecret, 7);;
    }
    else
    {
        _contacts[_nbr_Contacts] = Contact(firstName, lastName, nickname, phoneNumber, darkestSecret, _nbr_Contacts);
        _nbr_Contacts ++;
    }
}

void    printContactColumn(std::string column)
{
    int i = column.length();
    int j = 0;
    while ((j < 9) && (j < i))
        std::cout << column[j ++];

    if (i > 10)
        std::cout << ".";
    else if (i == 10)
        std::cout << column[9];
    while ((j < 10) && (i <= 10))
    {
        std::cout << " ";
        j ++;
    }
}

void    PhoneBook::search()
{
    int i = 0;
    int j;

    while (i < _nbr_Contacts)
    {
        j = 0;
        std::cout << _contacts[i].getIndex() << "         |";
        printContactColumn(_contacts[i].getFirstName());
        std::cout << "|";
        printContactColumn(_contacts[i].getLastName());
        std::cout << "|";
        printContactColumn(_contacts[i].getNickname());
        std::cout << std::endl;
        i ++;
    }
}
