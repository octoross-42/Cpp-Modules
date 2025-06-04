#include "PmergeMe.hpp"

void	showVector(const std::vector<int> &v)
{
	std::cout << B << "Vector: " << R;
	std::vector<int>::const_iterator it = v.begin();
	while (it != v.end())
	{
		std::cout << *it;
		it ++;
		if (it != v.end())
			std::cout << " ";
	}
	std::cout << std::endl;
}

void	splitVectors(std::vector<int> &vector, std::vector<int> &lower_values, std::vector<int> &upper_values)
{
	std::vector<int>::iterator it = vector.begin();
	lower_values.reserve((vector.size() + 1)/ 2);
	upper_values.reserve(vector.size() / 2);
	while (it != vector.end())
	{
		if ((it + 1) != vector.end())
		{
			if (*it < *(it + 1))
			{
				lower_values.push_back(*it);
				upper_values.push_back(*(it + 1));
			}
			else
			{
				lower_values.push_back(*(it + 1));
				upper_values.push_back(*it);
			}
			it += 2;
		}
		else
			lower_values.push_back(*(it ++));
	}
}

void	binaryInsertionVector(std::vector<int> &vector, int elmnt, int max_i_insertion)
{
	std::vector<int>::iterator it = std::lower_bound(vector.begin(), vector.begin() + max_i_insertion, elmnt);
	vector.insert(it, elmnt);
}

void	FordJonhsonMergeVectors(std::vector<int> &lower_values, std::vector<int> &upper_values)
{
	size_t	k = 1;
	size_t	i;
	size_t	tk = 1;
	size_t	max_i_insertion;
	size_t	tkbefore;
	upper_values.reserve(upper_values.size() + lower_values.size());
	upper_values.insert(upper_values.begin(), *lower_values.begin());
	size_t	nbr_inserted = 1;
	while (tk < lower_values.size())
	{
		tkbefore = tk;
		tk = (2 << k) - tk;
		k ++;
		i = tk;
		if (i > lower_values.size())
			i = lower_values.size();
		max_i_insertion = i - 1 + nbr_inserted;
		while (i >= tkbefore + 1)
		{
			i --;
			nbr_inserted ++;
			binaryInsertionVector(upper_values, lower_values.at(i), max_i_insertion);
		}
	}

}

void	FordJohnsonSortVector(std::vector<int> &vector)
{
	if (vector.size() <= 1)
		return ;
	std::vector<int> upper_values;
	std::vector<int> lower_values;
	splitVectors(vector, lower_values, upper_values);

	FordJohnsonSortVector(upper_values);
	
	FordJonhsonMergeVectors(lower_values, upper_values);
	vector.swap(upper_values);
}

void	mergeWithVector(const std::list<int> &list)
{
	// INIT VECTOR
	std::vector<int> v;
	v.reserve(list.size());
	std::list<int>::const_iterator it = list.begin();
	while (it != list.end())
	{
		v.push_back(*it);
		it ++;
	}

	// SORT VECTOR
	FordJohnsonSortVector(v);

	if (SHOW_CONTAINERS)
	{
		std::cout << std::endl;
		showVector(v);
	}
}


void	showDeque(const std::deque<int> &q)
{
	std::cout << B << "Deque: " << R;
	std::deque<int>::const_iterator it = q.begin();
	while (it != q.end())
	{
		std::cout << *it;
		it ++;
		if (it != q.end())
			std::cout << " ";
	}
	std::cout << std::endl;
}

void	splitDeques(std::deque<int> &deque, std::deque<int> &lower_values, std::deque<int> &upper_values)
{
	std::deque<int>::iterator it = deque.begin();
	while (it != deque.end())
	{
		if ((it + 1) != deque.end())
		{
			if (*it < *(it + 1))
			{
				lower_values.push_back(*it);
				upper_values.push_back(*(it + 1));
			}
			else
			{
				lower_values.push_back(*(it + 1));
				upper_values.push_back(*it);
			}
			it += 2;
		}
		else
			lower_values.push_back(*(it ++));
	}
}

void	binaryInsertionDeque(std::deque<int> &deque, int elmnt, int max_i_insertion)
{
	std::deque<int>::iterator it = std::lower_bound(deque.begin(), deque.begin() + max_i_insertion, elmnt);
	deque.insert(it, elmnt);
}

void	FordJonhsonMergeDeques(std::deque<int> &lower_values, std::deque<int> &upper_values)
{
	size_t	k = 1;
	size_t	i;
	size_t	tk = 1;
	size_t	max_i_insertion;
	size_t	tkbefore;
	upper_values.insert(upper_values.begin(), *lower_values.begin());
	size_t	nbr_inserted = 1;
	while (tk < lower_values.size())
	{
		tkbefore = tk;
		tk = (2 << k) - tk;
		k ++;
		i = tk;
		if (i > lower_values.size())
			i = lower_values.size();
		max_i_insertion = i - 1 + nbr_inserted;
		while (i >= tkbefore + 1)
		{
			i --;
			nbr_inserted ++;
			binaryInsertionDeque(upper_values, lower_values.at(i), max_i_insertion);
		}
	}

}

void	FordJohnsonSortDeque(std::deque<int> &deque)
{
	if (deque.size() <= 1)
		return ;
	std::deque<int> upper_values;
	std::deque<int> lower_values;
	splitDeques(deque, lower_values, upper_values);

	FordJohnsonSortDeque(upper_values);
	
	FordJonhsonMergeDeques(lower_values, upper_values);
	deque.swap(upper_values);
}

void	mergeWithDeque(const std::list<int> &list)
{
	// INIT VECTOR
	std::deque<int> d;
	std::list<int>::const_iterator it = list.begin();
	while (it != list.end())
	{
		d.push_back(*it);
		it ++;
	}

	// SORT VECTOR
	FordJohnsonSortDeque(d);

	if (SHOW_CONTAINERS)
	{
		std::cout << std::endl;
		showDeque(d);
	}
}
