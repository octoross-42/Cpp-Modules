/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 21:48:36 by octoross          #+#    #+#             */
/*   Updated: 2025/04/15 21:48:36 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef DATA_HPP

# define DATA_HPP

class	Data
{
	
	private:
		int		_intData;

	public:
		Data(void): _intData(0) {}
		Data(int i): _intData(i) {}
		Data(const Data &to_copy): _intData(to_copy._intData) {}
		Data &operator=(const Data &to_copy)
		{
			if (this == &to_copy)
				return (*this);
			_intData = to_copy._intData;
			return (*this);
		}
		~Data(void) {}

		int		getInt(void) const { return (_intData); }
		void	setInt(int n) { _intData = n; }
};

#endif