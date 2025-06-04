#ifndef BASE_HPP

# define BASE_HPP

# include <iostream>
# include <cstdlib>
# include <sstream>
# include <exception>

class Base
{
	public:
		virtual ~Base() {}
};

class A: public Base {};
class B: public Base {};
class C: public Base {};


template <typename T>
T	typeOfString(const std::string &str, const std::string &type)
{
	std::istringstream iss(str);
    T	value;
    
    if (!(iss >> value))
		throw std::runtime_error(str + " can't be converted to " + type);


	char remaining;
	if (iss.get(remaining))
		throw std::runtime_error(str + " can't be converted to " + type);
    return (value);
}


#endif