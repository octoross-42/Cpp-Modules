#ifndef RPN_HPP

# define RPN_HPP

# include <iostream>
# include <stack>

# define B "\033[1m"
# define R "\033[0m"

class RPN
{
	private:
		double _result;
		
		bool	isRPNDigit(char c);
		bool	isRPNOperand(char c);
		double	exec_operand(char op, double first, double second);

	public:
		RPN(int argc, char **argv);
		RPN(const RPN &to_copy): _result(to_copy._result) {}
		RPN	&operator=(const RPN &to_copy)
		{
			if (this == &to_copy)
				return (*this);
			_result = to_copy._result;
			return (*this);
		}
		~RPN() {}
	
		void	show_result(void);
};

#endif