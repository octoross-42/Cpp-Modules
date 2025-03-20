/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 22:16:27 by octoross          #+#    #+#             */
/*   Updated: 2025/03/06 22:51:13 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(Fixed(0)), _y(Fixed(0)) {}
		
Point::Point(const float x, const float y) : _x(Fixed(x)), _y(Fixed(y)) {}


const Fixed	Point::getX(void) const
{
    return (_x);
}

const Fixed	Point::getY(void) const
{
    return (_y); 
}

float Point::getFX(void) const
{
    return (_x.toFloat());
}

float Point::getFY(void) const
{
    return (_y.toFloat());
}

Point::Point(const Point &to_copy) : _x(to_copy.getX()), _y(to_copy.getY()) {}

Point::~Point() {}

std::ostream &operator<<(std::ostream &output, Point const &p)
{
    output << "( " << p.getX() << p.getY() << " )" << std::endl;
    return (output);
}

