/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 07:31:20 by octoross          #+#    #+#             */
/*   Updated: 2025/04/15 20:32:14 by octoross         ###   ########.fr       */
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

# define BOLD "\x1B[1m"
# define UNDERLINE "\x1B[4m"

# define RESET "\033[0m"

# define FLOAT_MANTISSA_SIZE 23
# define FLOAT_EXPONENT_SIZE 8
# define DOUBLE_MANTISSA_SIZE 52
# define DOUBLE_EXPONENT_SIZE 11

typedef struct s_scalar
{
	bool		isValid;
	bool		isFloat;
	bool		overflow;
	int			sign;
	long double	value;
	int			exponentValue;
	int			exponentSign;
	long double finalValue;
}			t_scalar;

enum eNumberType
{
	INT,
	FLOAT,
	DOUBLE
};

class ScalarConverter
{
	private:
		ScalarConverter(void);
		
		static void		pseudoLiterals(std::string literal);
		static void		printInvalid(std::string str);
		static void		printChar(long double finalValue);
		static bool		numberOverflows(long double value, eNumberType type);
		static int		getPrecision(long double value);
		static void		printNumber(t_scalar *scalar, eNumberType type, std::string typeStr);
			
		static bool		isExponentValid(t_scalar *scalar, std::string literal, size_t *i, bool *eFound);
		static t_scalar	*isFloatValid(t_scalar *scalar, bool stringEnded, size_t dotFound);
		
		static t_scalar	*getScalar(std::string literal);
		
		static void		calculateFinalValue(t_scalar *scalar);
		static bool		incrementScalarValue(t_scalar *scalar, int digitValue, size_t exponentPower, size_t dotFound, bool eFound);

	
	public:

		static void	convert(std::string literal);
};

#endif