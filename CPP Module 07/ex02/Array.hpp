/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 21:07:58 by octoross          #+#    #+#             */
/*   Updated: 2025/05/20 21:07:58 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP

# define ITER_HPP

# include <iostream>

template <typename T> class Array
{
	private:
		T	*_array;
		size_t	_size;
	public:
		Array(void) : _array(NULL), _size(0) {}

		Array(size_t n) : _array(new T[n]), _size(n)
		{
			std::cout << n << std::endl;
			for (size_t i = 0; i < n; ++i)
				_array[i] = T(0);
		}

		Array(const Array &to_copy) : _array(new T[to_copy._size]), _size(to_copy._size)
		{
			for (size_t i = 0; i < _size; ++i)
				_array[i] = to_copy._array[i];
		}

		Array &operator=(const Array &to_copy)
		{
			if (this == &to_copy)
				return (*this);
			delete [] _array;
			_size = to_copy._size;
			_array = new T[_size];
			for (size_t i = 0; i < _size; ++i)
				_array[i] = to_copy._array[i];
			return (*this);
		}
		
		size_t	size(void) const { return (_size);}

		T &operator[](size_t i)
		{
			if (i >= _size)
				throw std::out_of_range("Index out of range");
			return (_array[i]);
		}

		~Array(void)
		{
			delete [] _array;
		}
};

template <typename T>
std::ostream& operator<<(std::ostream& os, Array<T> arr)
{
    for (size_t i = 0; i < arr.size(); ++i)
	{
		os << arr[i];
		if (i != arr.size() - 1)
			os << ", ";
	}
    return (os);
}

#endif