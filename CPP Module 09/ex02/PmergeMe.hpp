#ifndef RPN_HPP

# define RPN_HPP

# include <iostream>
# include <vector>
# include <list>
# include <deque>
# include <iterator>
# include <sstream>
# include <algorithm>

// vector
// deque
// list -> pas de random accès 

// set / multiset / map / multimap -> trie quand insertion, pas pertinent
// stack /queue -> pas pratique

# define SHOW_CONTAINERS false

# define B "\033[1m"
# define R "\033[0m"

template <typename T>
T	typeOfString(const std::string &str, const std::string &type)
{
	std::istringstream iss(str);
    T	value;
    
    if (!(iss >> value))
		throw std::runtime_error(std::string("Error: '") + B + str + R + "' can't be converted to " + type);


	char remaining;
	if (iss.get(remaining))
		throw std::runtime_error(std::string("Error: '") + B + str + R + "' can't be converted to " + type);
    return (value);
}

void	mergeWithVector(const std::list<int> &list);
void	mergeWithDeque(const std::list<int> &list);

#endif