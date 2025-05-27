/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 23:40:12 by octoross          #+#    #+#             */
/*   Updated: 2025/05/27 22:23:22 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP

# define EASYFIND_TPP


struct true_type { static const bool yes = true; };
struct false_type { static const bool yes = false; };


template <typename T>
struct has_find_prototype: false_type {};

template <typename U, typename V>
struct has_find_prototype<std::map<U, V> >: true_type {};

template <typename U, typename V>
struct has_find_prototype<std::multimap<U, V> >: true_type {};

template <typename T>
struct has_find_prototype< std::set<T> >: true_type {};

template <typename T>
struct has_find_prototype< std::multiset<T> >: true_type {};

template <typename T>
typename T::iterator easyfind_specialisation(T& container, int value, true_type) {
    return (container.find(value));
}

template <typename T>
typename T::iterator easyfind_specialisation(T& container, int value, false_type) {
    return (std::find(container.begin(), container.end(), value));
}

template <typename T>
typename T::iterator easyfind(T& container, int value){
    return easyfind_specialisation(container, value, has_find_prototype<T>());
}

int	*easyfind(std::stack<int> stack, int value)
{
	while (!stack.empty())
	{
		if (stack.top() == value)
			return (&stack.top());
		stack.pop();
	}
	return (NULL);
}

int	*easyfind(std::queue<int> queue, int value)
{
	while (!queue.empty())
	{
		if (queue.front() == value)
			return (&queue.front());
		queue.pop();
	}
	return (NULL);
}




template <typename Container>
std::ostream	&printContainer(std::ostream& os, const Container &container)
{
	typename Container::const_iterator it = container.begin();
	os << "[ ";
	while (it != container.end())
	{
		os << *(it++);
		if (it != container.end()) os << ", ";
	}
	os << " ]";
	return (os);
}

template <typename PairContainer>
std::ostream	&printPairContainer(std::ostream& os, const PairContainer &container)
{
	typename PairContainer::const_iterator it = container.begin();
	os << "[ ";
	while (it != container.end())
	{
		os << it->first << " => " << it->second;
		if (++it != container.end()) os << ", ";
	}
	os << " ]";
	return (os);
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T> &vector)
{
	return printContainer(os, vector);
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::deque<T> &deque)
{
	return printContainer(os, deque);
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::list<T> &list)
{
	return printContainer(os, list);
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::set<T> &set)
{
	return printContainer(os, set);
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::multiset<T> &multiset)
{
	return printContainer(os, multiset);
}

// MAP

template <typename T, typename U>
std::ostream& operator<<(std::ostream& os, const std::map<T, U> &map)
{
	return printPairContainer(os, map);
}

template <typename T, typename U>
std::ostream& operator<<(std::ostream& os, const std::multimap<T, U> &mmap)
{
	return printPairContainer(os, mmap);
}



// STACK
template <typename T>
std::ostream& operator<<(std::ostream& os, std::stack<T> stack)
{
    os << "[ ";
    while (!stack.empty())
	{
        os << stack.top();
        stack.pop();
        if (!stack.empty()) os << ", ";
    }
    os << " ]";
    return (os);
}

// QUEUE
template <typename T>
std::ostream& operator<<(std::ostream& os, std::queue<T> queue)
{
    os << "[ ";
    while (!queue.empty())
	{
        os << queue.front();
        queue.pop();
        if (!queue.empty()) os << ", ";
    }
    os << " ]";
    return (os);
}


template <typename T>
std::ostream& operator<<(std::ostream& os, has_find_prototype<T> has_find)
{
	os << (has_find.yes ? "has find prototype" : "dont have find prototype");
	return (os);
}


#endif