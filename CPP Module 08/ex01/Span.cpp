#include "Span.hpp"

Span::Span(unsigned int n) : _is_sorted(true), _min(0), _max(0), _shortest_span(0), _capacity(n), _storage()
{
	_storage.reserve(n);
}

Span::Span(const Span &to_copy) : _is_sorted(to_copy._is_sorted), _min(to_copy._min), _max(to_copy._max), _shortest_span(to_copy._shortest_span), _capacity(to_copy._capacity), _storage(to_copy._storage) {}

Span &Span::operator=(const Span &to_copy)
{
	if (this == &to_copy)
		return (*this);
	_is_sorted = to_copy._is_sorted;
	_storage = to_copy._storage;
	_shortest_span = to_copy._shortest_span;
	_capacity = to_copy._capacity;
	_min = to_copy._min;
	_max = to_copy._max;
	return (*this);
}

void Span::addNumber(int number)
{
	if (_capacity == _storage.size())
		throw std::length_error("Storage is full, cannot add more numbers.");

	_storage.push_back(number);
	if (_storage.size() == 1)
	{
		_min = number;
		_max = number;
	}
	else
	{
		_is_sorted = false;
		if (number < _min)
			_min = number;
		if (number > _max)
			_max = number;
	}
}

void	Span::addNumber(const std::vector<int>::const_iterator &begin, const std::vector<int>::const_iterator &end)
{
	// unsigned int	i = 0;
	
	std::vector<int>::const_iterator it = begin;
	while (it != end)
		addNumber(*(it++));
}

unsigned int Span::shortestSpan(void)
{
	if (_storage.size() < 2)
		throw std::length_error("Not enough elements to find a span.");
	

	if (!_is_sorted)
	{
		std::sort(_storage.begin(), _storage.end());
		_is_sorted = true;
	}
	else
		return (_shortest_span);
    
    int shortest = INT_MAX;

	size_t i = 1;
    while (i < _storage.size())
	{
        int current_distance = _storage[i] - _storage[i - 1];
        if (current_distance < shortest)
            shortest = current_distance;
		if (current_distance == 0)
			return (shortest);
		i ++;
    }
	_shortest_span = shortest;
	return (shortest);
}

unsigned int Span::longestSpan(void) const
{
	return (_max - _min);
}

std::ostream& operator<<(std::ostream& os, const Span &span)
{
	typename std::vector<int>::const_iterator it = span.begin();
	os << "[ ";
	while (it != span.end())
	{
		os << *(it++);
		if (it != span.end()) os << ", ";
	}
	os << " ]";
	return (os);
}

