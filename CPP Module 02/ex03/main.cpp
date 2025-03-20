/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:59:24 by octoross          #+#    #+#             */
/*   Updated: 2025/03/06 22:55:17 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main(int argc, char **argv)
{
    const Point a;
    const Point b(3, 0);
    const Point c(0, 3);

    if (argc > 2)
    {
        const Point point(atoi(argv[1]), atoi(argv[2]));
        std::cout << bsp(a, b, c, point) << std::endl;
    } 
    else
    {
        const Point point(1, 1.5);
        std::cout << bsp(a, b, c, point) << std::endl;
    }
    return (0);
}
