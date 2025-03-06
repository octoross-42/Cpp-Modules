/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 18:29:40 by octoross          #+#    #+#             */
/*   Updated: 2025/03/06 19:02:59 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
    _fixed_value = 0;
    std::cout << "Default constructor called";
    std::cout << std::endl;
}

Fixed::Fixed(const int value)
{
    std::cout << "Int Constructor called";
    std::cout << std::endl;
    _fixed_value = (value << _nbr_fract_bits);
}

Fixed::Fixed(const float value)
{
    std::cout << "Float Constructor called";
    std::cout << std::endl;
    _fixed_value = roundf(value << _nbr_fract_bits);
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called";
    std::cout << std::endl;
}

Fixed::Fixed(const Fixed &to_copy)
{
    std::cout << "Copy constructor called";
    std::cout << std::endl;
    _fixed_value = to_copy.getRawBits();
}

Fixed  &Fixed::operator= (Fixed &to_copy)
{
    std::cout << "Copy assignment constructor called";
    std::cout << std::endl;
    if (this == &to_copy)
        return (*this);
    _fixed_value = to_copy.getRawBits();
    return (*this);
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called";
    std::cout << std::endl;
    return (_fixed_value);
}
void    Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called";
    std::cout << std::endl;
    _fixed_value = raw;
}

float toFloat(void) const
{
    std::cout << "Convert to float called";
    std::cout << std::endl;
    return (_fixed_value)
}

int toInt(void) const
{
    std::cout << "Convert to int called";
    std::cout << std::endl;   
}
