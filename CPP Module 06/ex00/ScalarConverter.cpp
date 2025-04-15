/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 07:31:20 by octoross          #+#    #+#             */
/*   Updated: 2025/04/15 21:36:41 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void	ScalarConverter::printInvalid(std::string str)
{
	std::cout << BOLD << "ScalarConverter: " << RESET << "\"" << BYELLOW << str << RESET << "\" is not a valid input" << std::endl;
}

void	ScalarConverter::pseudoLiterals(std::string literal)
{
	std::cout << BOLD << "ScalarConverter" << RESET << " for \'" << BYELLOW << literal << RESET << "\'" << std::endl;		
	std::cout << BGREEN << "\tchar   " << RESET << "impossible" << std::endl;
	std::cout << BGREEN << "\tint    " << RESET << "impossible" << std::endl;

	float floatInf = std::numeric_limits<float>::infinity();
	double doubleInf = std::numeric_limits<double>::infinity();
	if (literal[0] == 'n')
	{
		std::cout << BGREEN << "\tfloat  " << RESET << "nanf" << std::endl;
		std::cout << BGREEN << "\tdouble " << RESET << "nan" << std::endl;
	}
	else
	{
		int sign = (literal[0] == '+') ? 1 : -1;
		std::cout << BGREEN << "\tfloat  " << RESET << sign * floatInf << std::endl;
		if (literal.length() == 4)
			std::cout << BGREEN << "\tdouble " << RESET << sign * doubleInf << std::endl;
		else
			std::cout << BGREEN << "\tdouble " << RESET << sign * floatInf << std::endl;
	}
}

void	ScalarConverter::printChar(long double finalValue)
{
	if ((finalValue > CHAR_MAX) || (finalValue < CHAR_MIN))
		std::cout << BRED << "\tchar   " << RESET << "impossible" << std::endl;
	else if ((finalValue < 32) || (finalValue > 126))
		std::cout << BRED << "\tchar   " << RESET << "non-printable character" << std::endl;
	else
		std::cout << BGREEN << "\tchar   " << RESET << (char)finalValue << std::endl;
}

bool	ScalarConverter::numberOverflows(long double value, eNumberType type)
{
	if (type == INT)
		return ((value > INT_MAX) || (value < INT_MIN));
	else if (type == FLOAT)
		return ((value > FLT_MAX) || (value < -FLT_MAX));
	else if (type == DOUBLE)
		return ((value > DBL_MAX) || (value < -DBL_MAX));
	return (false);
}

int	ScalarConverter::getPrecision(long double value)
{
	int	precision = 0;
	long double floorValue = floor(value);
	long double decimalValue = value - floorValue;
	while (decimalValue != 0)
	{
		decimalValue *= 10;
		decimalValue -= floor(decimalValue); 
		precision ++;
	}
	return (precision);
}

void	ScalarConverter::printNumber(t_scalar *scalar, eNumberType type, std::string typeStr)
{
	if (!scalar->isValid)
		std::cout << BRED << "\t" << typeStr << RESET << "impossible" << std::endl;
	else if (scalar->overflow || numberOverflows(scalar->finalValue, type))
		std::cout << BRED << "\t" << typeStr << RESET << "overflow" << std::endl;
	else
	{
		std::cout << BGREEN << "\t" << typeStr << RESET;
		std::ostringstream oss;
		if (type == INT)
			oss << static_cast<int>(scalar->finalValue);
		else if (type == FLOAT)
		{
			float floatValue = static_cast<float>(scalar->finalValue);
			int precision = getPrecision(floatValue);
			oss << std::fixed << std::setprecision(precision);
			oss << floatValue << ((precision == 0) ? ".0f" : "f");
		}
		else if (type == DOUBLE)
		{
			double doubleValue = static_cast<double>(scalar->finalValue);
			int precision = getPrecision(doubleValue);
			oss << std::fixed << std::setprecision(precision);
			oss << doubleValue;
			if (precision == 0)
				oss << ".0";
		}
		std::string scalarStr = oss.str();
		std::cout << scalarStr << std::endl;
	}
}

t_scalar	*newScalar(void)
{
	t_scalar *scalar = new t_scalar;
	if (!scalar)
		return (NULL);
	
	scalar->isValid = true;
	scalar->isFloat = false;
	scalar->overflow = false;
	scalar->sign = 1;
	scalar->value = 0;
	scalar->exponentSign = 1;
	scalar->exponentValue = 1;
	scalar->finalValue = 0;
	return (scalar);
}

bool	ScalarConverter::isExponentValid(t_scalar *scalar, std::string literal, size_t *i, bool *eFound)
{
	if (*eFound)
		return (false);

	*eFound = true;
	if (*i == literal.length() - 1)
		return (false);
	if ((literal[*i + 1] == '-') || (literal[*i + 1] == '+'))
	{
		if (literal[*i + 1] == '-')
			scalar->exponentSign = -1;
		(*i)++;
		if (*i == literal.length() - 1)
			return (false);
	}
	return (true);
}	

t_scalar	*ScalarConverter::isFloatValid(t_scalar *scalar, bool stringEnded, size_t dotFound)
{
	if (!stringEnded)
		return (scalar->isValid = false, scalar);
	if (dotFound == 0)
		return (scalar->isValid = false, scalar);
	scalar->isFloat = true;
	calculateFinalValue(scalar);
	if ((scalar->finalValue > FLT_MAX) || (scalar->finalValue < -FLT_MAX))
	{
		scalar->overflow = true;
		return (scalar);
	}
	return (scalar);
}

bool	ScalarConverter::incrementScalarValue(t_scalar *scalar, int digitValue, size_t decimalCount, size_t dotFound, bool eFound)
{
	if (eFound)
	{
		scalar->exponentValue = scalar->exponentValue * 10 + digitValue;
		if (scalar->exponentValue > DBL_MAX_10_EXP)
		{
			scalar->overflow = true;
			return (false);
		}
	}
	else
	{
		if (dotFound == 0)
		{
			scalar->value = scalar->value * 10 + digitValue;
			if (((scalar->value > DBL_MAX) && !scalar->isFloat)
				|| ((scalar->value > FLT_MAX) && scalar->isFloat))
			{
				scalar->overflow = true;
				return (false);
			}
		}
		else if (digitValue != 0)
			scalar->value = scalar->value + (digitValue / pow(10, decimalCount));
	}
	return (true);
}

void	ScalarConverter::calculateFinalValue(t_scalar *scalar)
{
	if ((scalar->exponentValue == 1) && (scalar->exponentSign == 1))
		scalar->finalValue = scalar->value * scalar->sign;
	else
		scalar->finalValue = (scalar->value * scalar->sign) * pow(10, scalar->exponentSign * scalar->exponentValue);
}

t_scalar	*ScalarConverter::getScalar(std::string literal)
{
	t_scalar *scalar = newScalar();
	if (!scalar)
		return (NULL);

	size_t i = ((literal[0] == '-') || (literal[0] == '+'));
	if (literal[0] == '-')
		scalar->sign = -1;
	if ((literal[i] < '0' ) || (literal[i] > '9' ))
		return (scalar->isValid = false, scalar);
	scalar->value = literal[i ++] - '0';

	size_t	dotFound = 0;
	bool	eFound = false;
	while (i < literal.length())
	{
		if (literal[i] == '.')
		{
			if ((dotFound > 0) || eFound)
				return (scalar->isValid = false, scalar);
			dotFound = i;
		}
		else if ((literal[i] == 'e') || (literal[i] == 'E'))
		{
			if (!isExponentValid(scalar, literal, &i, &eFound))
				return (scalar->isValid = false, scalar);
			scalar->exponentValue = 0;
		}
		else if ((literal[i] == 'f') || (literal[i] == 'F'))
			return (isFloatValid(scalar, (literal.length() - 1) == i, dotFound));
	
		else if ((literal[i] < '0') || (literal[i] > '9'))
			return (scalar->isValid = false, scalar);
		else
			incrementScalarValue(scalar, literal[i] - '0', i - dotFound, dotFound, eFound);
		i ++;
	}
	calculateFinalValue(scalar);
	return (scalar);
}

void	ScalarConverter::convert(std::string literal)
{
	if ((literal == "nan") || (literal == "nanf")
		|| (literal == "+inf") || (literal == "-inf")
		|| (literal == "+inff") || (literal == "-inff"))
		ScalarConverter::pseudoLiterals(literal);
	else
	{
		t_scalar *scalar = getScalar(literal);
		if (!scalar)
		{
			std::cout << BOLD << "ScalarConverter: " << RESET << "Memory allocation failed" << std::endl;
			return ;
		}
		if (!scalar->isValid && literal.length() > 1)
			printInvalid(literal);
		else
		{
			std::cout << BOLD << "ScalarConverter" << RESET << " for \'" << BYELLOW << literal << RESET << "\'" << std::endl;
			printChar(scalar->finalValue);
			printNumber(scalar, INT, "int    ");
			printNumber(scalar, FLOAT, "float  ");
			printNumber(scalar, DOUBLE, "double ");
		}
		delete scalar;
	}
	
}

