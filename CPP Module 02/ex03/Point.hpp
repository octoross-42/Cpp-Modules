/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 22:08:17 by octoross          #+#    #+#             */
/*   Updated: 2025/03/06 22:51:16 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP

# define POINT_HPP

# include "Fixed.hpp"

class   Point
{
	private:
		const Fixed _x;
		const Fixed	_y;

	public:
		Point(void);
		Point(const float x, const float y);
		Point(const Point &to_copy);
		~Point(void);
		
		const Fixed	getX(void) const;
		const Fixed	getY(void) const;
		float	getFX(void) const;
		float	getFY(void) const;
};

std::ostream &operator<<(std::ostream &output, Point const &p);

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif