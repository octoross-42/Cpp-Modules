#include "RPN.hpp"

bool	RPN::isRPNDigit(char c)
{
	return ((c >= '0') && (c <= '9'));
}

bool	RPN::isRPNOperand(char c)
{
	return ((c == '+') || (c == '-') || (c == '*') || (c == '/'));
}

double	RPN::exec_operand(char op, double first, double second)
{
	if (op == '+')
		return (second + first);
	else if (op == '-')
		return (second - first);
	else if (op == '*')
		return (second * first);
	else if (op == '/')
	{
		if (first == 0)
			throw std::logic_error("Error: division by 0 not allowed");
		return (second / first);
	}
	else
		throw std::logic_error("Error:  doesnt respect inverted Polish mathematical expression format :)");
}

RPN::RPN(int argc, char **argv)
{
	int i = 0;
	int k, j;
	std::string o;
	std::stack<double> stack;
	double first, second, result;
	while (i < argc)
	{
		j = 0;
		k = 0;
		while (argv[i][j])
		{
			while (std::isspace(argv[i][j]))
				j ++;
			k = j;
			while (argv[i][j] && !std::isspace(argv[i][j]))
				j ++;
			if (j - k == 0)
				break;
			else if (j - k != 1)
				throw std::runtime_error(std::string("Error: invalid paramater:  ") + B + std::string(argv[i]).substr(k, j - k) + R);


			if (isRPNDigit(argv[i][k]))
				stack.push(argv[i][k] - '0');
			else if (isRPNOperand(argv[i][k]))
			{
				if (stack.size() < 2)
					throw std::logic_error("Error: doesnt respect inverted Polish mathematical expression format :)");
				first = stack.top();
				stack.pop();
				second = stack.top();
				stack.pop();
				result = exec_operand(argv[i][k], first, second);
				stack.push(result);
			}
			else
				throw std::runtime_error(std::string("Error: invalid paramater:  ") + B + argv[i][k] + R);
		}
		i ++;
	}
	if (stack.size() != 1)
		throw std::logic_error("Error: doesnt respect inverted Polish mathematical expression format :)");
	_result = stack.top();
}


void	RPN::show_result(void)
{
	std::cout << _result << std::endl;
}