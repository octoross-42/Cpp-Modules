/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 21:32:45 by octoross          #+#    #+#             */
/*   Updated: 2025/03/05 21:54:16 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(int argc, char **argv)
{
    int n = 5;
    std::string name = "Bob";

    if (argc >= 3)
    {
        n = atoi(argv[1]);
        name = argv[2];
    }
    Zombie  *horde = zombieHorde(n, name);
    int i = 0;
    while (i < n)
        horde[i ++].announce();
    delete [] horde;
}
