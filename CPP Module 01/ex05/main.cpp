/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 00:02:46 by octoross          #+#    #+#             */
/*   Updated: 2025/03/06 00:27:32 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
    Harl    harl;
    std::string level = "INFO";

    if (argc > 1)
        level = argv[1];
    harl.complain(level);
    return (0);
}
