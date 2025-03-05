/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 19:49:21 by octoross          #+#    #+#             */
/*   Updated: 2025/03/05 21:25:57 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(int argc, char **argv)
{
    std::string alloc_method;
    int i = 1;
    
    while (i < argc)
    {
        std::cout << "Heap Or Stack ? ";
        std::getline(std::cin, alloc_method);
        if (alloc_method == "Heap")
        {
            Zombie  *zh = newZombie(argv[i]);
            delete zh;
        }
        else
            randomChump(argv[i]);
        std::cout << std::endl;
        i ++;
    }
}
