/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 15:42:36 by octoross          #+#    #+#             */
/*   Updated: 2025/05/11 15:42:36 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP

# define WHATEVER_HPP

# include <iostream>

template <typename T> void	swap(T &a, T &b)
{
	T	tmp = a;

	a = b;
	b = tmp;
}

template <typename T> T	min(const T &a, const T &b)
{
	return (a < b ? a: b);
}

template <typename T> T	max(const T &a, const T &b)
{
	return (a > b ? a: b);
}

#endif