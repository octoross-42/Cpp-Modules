#ifndef SPAN_HPP

# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <climits>
# include <cstdlib>
# include <ctime>

# define B "\033[1m"
# define UNDERLINE "\033[4m"
# define R "\033[0m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define WHITE "\033[37m"
# define BLACK "\033[30m"
# define BRED "\033[1;31m"
# define BGREEN "\033[1;32m"
# define BYELLOW "\033[1;33m"
# define BBLUE "\033[1;34m"
# define BMAGENTA "\033[1;35m"
# define BCYAN "\033[1;36m"
# define BWHITE "\033[1;37m"
# define BBLACK "\033[1;30m"
# define BUNDERLINE "\033[1;4m"
# define BR "\033[1;0m"

class Span
{
	private:
		bool	_is_sorted;
		int	_min;
		int	_max;
		unsigned _shortest_span;
		unsigned int _capacity;
		std::vector<int> _storage;
	public:
		Span(unsigned int n);
		Span(const Span &to_copy);
		Span &operator=(const Span &to_copy);
		~Span(void) {};

		void addNumber(int number);
		void addNumber(const std::vector<int>::const_iterator &begin, const std::vector<int>::const_iterator &end);

		unsigned int shortestSpan(void);
		unsigned int longestSpan(void) const;

		std::vector<int>::const_iterator begin(void) const { return _storage.begin(); }
		std::vector<int>::const_iterator end(void) const { return _storage.end(); }
};


std::ostream& operator<<(std::ostream& os, const Span &span);


#endif