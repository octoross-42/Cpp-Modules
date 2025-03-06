/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:52:02 by octoross          #+#    #+#             */
/*   Updated: 2025/03/06 19:01:32 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP

# define FIXED_HPP

# include <iostream>

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
        Fixed &operator= (Fixed &to_copy);
        int getRawBits(void) const;
        void    setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;
};

#endif