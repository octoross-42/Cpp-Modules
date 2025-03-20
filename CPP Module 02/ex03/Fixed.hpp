/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:52:02 by octoross          #+#    #+#             */
/*   Updated: 2025/03/06 22:04:12 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP

# define FIXED_HPP

# include <iostream>
# include <cmath>
# include <fstream>

class   Fixed
{
    private:
        int             _fixed_value;
        static const int   _nbr_fract_bits = 8;
    public:
        Fixed(void);
        Fixed(const int value);
        Fixed(const float value);
        ~Fixed(void);
        Fixed(const Fixed &to_copy);
        int getRawBits(void) const;
        void    setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;
        Fixed  &operator= (const Fixed &to_copy);
        bool    operator< (const Fixed fixed);
        bool    operator> (const Fixed fixed);
        bool    operator<=(const Fixed fixed);
        bool    operator>=(const Fixed fixed);
        bool    operator==(const Fixed fixed);
        bool    operator!=(const Fixed fixed);
        float   operator+ (const Fixed fixed);
        float   operator- (const Fixed fixed);
        float   operator* (const Fixed fixed);
        float   operator/ (const Fixed fixed);
        Fixed   &operator++(void);
        Fixed   &operator--(void);
        Fixed   operator++(int);
        Fixed   operator--(int);
        static Fixed   &min(Fixed &a, Fixed &b);
        static const Fixed   &min(const Fixed &a, const Fixed &b);
        static Fixed   &max(Fixed &a, Fixed &b);
        static const Fixed   &max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &output, Fixed const &f);

#endif