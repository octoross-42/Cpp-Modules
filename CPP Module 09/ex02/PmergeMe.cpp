#include "PmergeMe.hpp"

void	splitVectors(std::vector<int> &vector, std::vector<int> &first, std::vector<int> &second)
{
	std::vector<int>::iterator middle = vector.begin() + vector.size() / 2;
    first.assign(vector.begin(), middle);
	second.assign(middle, vector.end());
}

void	mergeVectors(std::vector<int> &vector, std::vector<int> &first, std::vector<int> &second)
{
	long unsigned int i = 0;
	long unsigned int j = 0;
	long unsigned int k = 0;
	while ((i < first.size()) && (j < second.size()))
	{
		if (first[i] < second[j])
			vector[k ++] = first[i ++];
		else
			vector[k ++] = second[j ++];
	}
	while (i < first.size())
		vector[k ++] = first[i ++];
	while (j < second.size())
		vector[k ++] = second[j ++];
}

void	sortVector(std::vector<int> &vector)
{
	if (vector.size() <= 1)
		return ;
	std::vector<int> second;
	std::vector<int> first;
	splitVectors(vector, first, second);

	sortVector(first);
	sortVector(second);
	
	mergeVectors(vector, first, second);
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
	sortVector(v);



	// SHOW VECTOR
	if (SHOW_CONTAINERS)
	{
		std::cout << B << "Vector: " << R;
		std::vector<int>::iterator it = v.begin();
		while (it != v.end())
		{
			std::cout << *it;
			it ++;
			if (it != v.end())
				std::cout << " ";
		}
		std::cout << std::endl;
	}
}


void	splitLists(std::list<int> &first, std::list<int> &second)
{
	std::list<int>::iterator middle = first.begin();
    std::advance(middle, first.size() / 2);
    
    second.splice(second.begin(), first, middle, first.end());
}

void	sortList(std::list<int> &list)
{
	if (list.size() <= 1)
		return ;
	std::list<int> second;
	splitLists(list, second);
	sortList(list);
	sortList(second);
	list.merge(second);
}


void	mergeWithList(const std::list<int> &list)
{
	// INIT LIST
	std::list<int> l;
	std::list<int>::const_iterator it = list.begin();
	while (it != list.end())
	{
		l.push_back(*it);
		it ++;
	}

	// SORT LIST
	sortList(l);

	// SHOW LIST
	if (SHOW_CONTAINERS)
	{
		std::cout << B << "List: " << R;
		std::list<int>::iterator it = l.begin();
		while (it != l.end())
		{
			std::cout << *it;
			it ++;
			if (it != l.end())
				std::cout << " ";
		}
		std::cout << std::endl;
	}
}