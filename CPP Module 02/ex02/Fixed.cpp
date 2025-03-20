/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 18:29:40 by octoross          #+#    #+#             */
/*   Updated: 2025/03/06 21:54:47 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
    _fixed_value = 0;
}

Fixed::Fixed(const int value)
{
    _fixed_value = (value << _nbr_fract_bits);
}

Fixed::Fixed(const float value)
{
    _fixed_value = roundf(value * ( 1 << _nbr_fract_bits));
}

Fixed::~Fixed(void)
{
}

Fixed::Fixed(const Fixed &to_copy)
{
    _fixed_value = to_copy.getRawBits();
}

float Fixed::toFloat(void) const
{
    return (((float)_fixed_value) /(1 << _nbr_fract_bits));
}

int Fixed::toInt(void) const
{
    return (_fixed_value >> _nbr_fract_bits);
}

Fixed  &Fixed::operator= (const Fixed &to_copy)
{
    if (this == &to_copy)
        return (*this);
    _fixed_value = to_copy.getRawBits();
    return (*this);
}

int Fixed::getRawBits(void) const
{
    return (_fixed_value);
}
void    Fixed::setRawBits(int const raw)
{
    _fixed_value = raw;
}

std::ostream &operator<<(std::ostream &output, Fixed const &f)
{
    output << f.toFloat();
    return (output);
}

bool    Fixed::operator< (const Fixed fixed)
{
    return (_fixed_value < fixed.getRawBits());
}

bool    Fixed::operator> (const Fixed fixed)
{
    return (_fixed_value > fixed.getRawBits());
}

bool    Fixed::operator<=(const Fixed fixed)
{
    return (_fixed_value <= fixed.getRawBits());
}

bool    Fixed::operator>=(const Fixed fixed)
{
    return (_fixed_value >= fixed.getRawBits());
}

bool    Fixed::operator==(const Fixed fixed)
{
    return (_fixed_value == fixed.getRawBits());
}

bool    Fixed::operator!=(const Fixed fixed)
{
    return (_fixed_value != fixed.getRawBits());
}

float    Fixed::operator+ (const Fixed fixed)
{
    int add = _fixed_value + fixed.getRawBits();  
    return (((float)add) /(1 << _nbr_fract_bits));
}

float    Fixed::operator- (const Fixed fixed)
{
    int add = _fixed_value - fixed.getRawBits();  
    return (((float)add) /(1 << _nbr_fract_bits));
}

float    Fixed::operator* (const Fixed fixed)
{
    return (this->toFloat() * fixed.toFloat());
}

float    Fixed::operator/ (const Fixed fixed)
{
    return (this->toFloat() / fixed.toFloat());
}

Fixed    &Fixed::operator++(void)
{
    _fixed_value ++;
    return (*this);
}

Fixed    &Fixed::operator--(void)
{
    _fixed_value --;
    return (*this);
}

Fixed    Fixed::operator++(int)
{
    Fixed   before_op = *this;
    ++_fixed_value;
    return (before_op);
}

Fixed    Fixed::operator--(int)
{
    Fixed   before_op = *this;
    --_fixed_value;
    return (before_op);
}

Fixed   &Fixed::min(Fixed &a, Fixed &b)
{
    if (a.getRawBits() > b.getRawBits())
        return (b);
    return (a);
}

const   Fixed   &Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a.getRawBits() > b.getRawBits())
        return (b);
    return (a);
}

Fixed   &Fixed::max(Fixed &a, Fixed &b)
{
    if (a.getRawBits() <= b.getRawBits())
        return (b);
    return (a);
}

const   Fixed   &Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a.getRawBits() <= b.getRawBits())
        return (b);
    return (a);
}
