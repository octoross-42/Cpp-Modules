/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 22:37:16 by octoross          #+#    #+#             */
/*   Updated: 2025/03/06 22:50:33 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static float    area(const Point a, const Point b, const Point c)
{
    float   area = (      (a.getFX() * (b.getFY() - c.getFY()))
                + (b.getFX() * (c.getFY() - a.getFY()))
                + (c.getFX() * (a.getFY() - b.getFY())));
    if (area >= 0)
        return (area);
    else
        return (-area);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    float   a1, a2, a3, a0;

    a0 = area(a, b, c);
    a1 = area(point, a, b);
    a2 = area(point, b, c);
    a3 = area(point, a, c);

    if ((a1 == 0) || (a2 == 0) || (a3 == 0))
        return (false);
    else if (a1 + a2 + a3 == a0)
        return (true);
    return (false);
}
