/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 00:09:06 by octoross          #+#    #+#             */
/*   Updated: 2025/03/06 00:30:17 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void) {}
Harl::~Harl(void) {}

void Harl::debug(void)
{
    std::cout << "[DEBUG]\t";
    std::cout << DEBUG_EXAMPLE << std::endl;
}

void Harl::info(void)
{

    std::cout << "[INFO]\t";
    std::cout << INFO_EXAMPLE << std::endl;
}

void Harl::warning(void)
{
    std::cout << "[WARNING]\t";
    std::cout << WARNING_EXAMPLE << std::endl;
}

void Harl::error(void)
{
    std::cout << "[ERROR]\t";
    std::cout << ERROR_EXAMPLE << std::endl;
}


void Harl::complain(std::string level)
{
    void    (Harl::*complain_func[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string complain_lvl[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    
    int i = 0;
    while (i < 4)
    {
        if (complain_lvl[i] == level)
        {
            (this->*complain_func[i])();
            break ;
        }
        i ++;
    }
}
