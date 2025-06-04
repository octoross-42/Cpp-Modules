/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 07:31:20 by octoross          #+#    #+#             */
/*   Updated: 2025/06/04 21:46:50 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP

# define SCALARCONVERTER_HPP

# include <iostream>
# include <iomanip>
# include <sstream>
# include <string>
# include <cstring>
# include <cmath>
# include <cfloat>
# include <climits>
# include <limits>

# define RED "\033[0;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define CYAN "\033[0;36m"
# define MAGENTA "\033[0;35m"

# define BRED "\x1B[1m\033[0;31m"
# define BGREEN "\x1B[1m\033[1;32m"
# define BYELLOW "\x1B[1m\033[1;33m"
# define BCYAN "\x1B[1m\033[0;36m"
# define BMAGENTA "\x1B[1m\033[0;35m"

# define B "\x1B[1m"
# define U "\x1B[4m"

# define R "\033[0m"

# include <stdint.h>

class Data;

template <typename T>
T	typeOfString(const std::string &str, const std::string &type)
{
	std::istringstream iss(str);
    T	value;
    
    if (!(iss >> value))
		throw std::runtime_error(str + " can't be converted to " + type);


	char remaining;
	if (iss.get(remaining))
		throw std::runtime_error(str + " can't be converted to " + type);
    return (value);
}


class Serializer
{
	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};

#endif