/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 21:07:58 by octoross          #+#    #+#             */
/*   Updated: 2025/05/20 21:07:58 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP

# define ITER_HPP

# include <iostream>

template <typename T> void	iter(T *arr, size_t len, void (*func)(T &))
{
	if (!arr || !func)
		return ;
	size_t	i = 0;
	while (i < len)
		func(arr[i ++]);
}

template <typename T> void	test(T &a)
{
	std::cout << a << " ";
	a ++;
	std::cout << a << std::endl;
}

#endif