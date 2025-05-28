
#ifndef MUTANTSTACK_TPP

# define MUTANTSTACK_TPP

# include <stack>
# include <iostream>

template <typename T>
class MutantStack: public std::stack<T>
{
	public:
		MutantStack(void): std::stack<T>() {}
		MutantStack(const MutantStack &to_copy): std::stack<T>(to_copy) {}
		MutantStack &operator=(const MutantStack &to_copy)
		{
			if (this == &to_copy)
				return (*this);
			std::stack<T>::operator=(to_copy);
			return (*this);
		}
		~MutantStack(void) {}

		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin() { return (this->c.begin()); }
		iterator end() { return (this->c.end()); }
		
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		const_iterator begin() const { return (this->c.begin()); }
		const_iterator end() const { return (this->c.end()); }
		
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		reverse_iterator rbegin() { return (this->c.rbegin()); }
		reverse_iterator rend() { return (this->c.rend()); }
		
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
		const_reverse_iterator rbegin() const { return (this->c.rbegin()); }
		const_reverse_iterator rend() const { return (this->c.rend()); }
};


template <typename T>
std::ostream	&operator<<(std::ostream &os, const MutantStack<T> &mstack)
{
	typename MutantStack<T>::const_reverse_iterator	it = mstack.rbegin();
	os << "[ ";
	while (it != mstack.rend())
	{
		os << *(it ++);
		if (it != mstack.rend())
			os << ",";
		os << " ";
	}
	os << "]";
	return (os);
}

#endif