#include "easyfind.hpp"

void	test_sequenceContainers()
{
	std::cout << BBLUE << "======================= Sequence Containers =======================" << R << std::endl;
	std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	std::deque<int> d;
	d.push_back(1);
	d.push_back(2);
	d.push_back(3);
    std::list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);

	std::cout << std::endl << BBLUE << "vector" << std::endl << R << "⤷ " << has_find_prototype< std::vector<int> >() << std::endl;
	std::cout << v << std::endl;
	std::cout << " ⤷ 2: " << ((easyfind(v, 2) != v.end()) ? "in": "not in") << std::endl;
	std::cout << " ⤷ 5: " << ((easyfind(v, 5) != v.end()) ? "in": "not in") << std::endl;
	
	std::cout << std::endl << BBLUE << "deque" << std::endl << R << "⤷ " << has_find_prototype< std::vector<int> >() << std::endl;
	std::cout << d << std::endl;
	std::cout << " ⤷ 2: " << ((easyfind(d, 2) != d.end()) ? "in": "not in") << std::endl;
	std::cout << " ⤷ 5: " << ((easyfind(d, 5) != d.end()) ? "in": "not in") << std::endl;
	
	std::cout << std::endl << BBLUE << "list" << std::endl << R << "⤷ " << has_find_prototype< std::list<int> >() << std::endl;
	std::cout << l << std::endl;
	std::cout << " ⤷ 2: " << ((easyfind(l, 2) != l.end()) ? "in": "not in") << std::endl;
	std::cout << " ⤷ 5: " << ((easyfind(l, 5) != l.end()) ? "in": "not in") << std::endl;
	
	std::cout << BBLUE << "====================================================================" << R << std::endl << std::endl;
}

void	test_associativeContainers()
{
	std::cout << BRED << "====================== Associative Containers ======================" << R << std::endl;
	std::set<int> set;
	set.insert(1);
	set.insert(1);
	set.insert(2);
	set.insert(3);

	std::multiset<int> mset;
	mset.insert(1);
	mset.insert(1);
	mset.insert(2);
	mset.insert(3);

	std::map<int, int> map;
	map[1] = 10;
	map[2] = 20;
	map[3] = 30;

	std::multimap<int, int> mmap;
	mmap.insert(std::pair<int, int>(1, 10));
	mmap.insert(std::pair<int, int>(1, 50));
	mmap.insert(std::pair<int, int>(2, 20));
	mmap.insert(std::pair<int, int>(3, 30));
	
	
	std::cout << std::endl << BRED << "set" << std::endl << R << "⤷ " << has_find_prototype< std::set<int> >() << std::endl;
	std::cout << set << std::endl;
	std::cout << " ⤷ 2: " << ((easyfind(set, 2) != set.end()) ? "in": "not in") << std::endl;
	std::cout << " ⤷ 5: " << ((easyfind(set, 5) != set.end()) ? "in": "not in") << std::endl;
	
	
	std::cout << std::endl << BRED << "multiset" << std::endl << R << "⤷ " << has_find_prototype< std::multiset<int> >() << std::endl;
	std::cout << mset << std::endl;
	std::cout << " ⤷ 2: " << ((easyfind(mset, 2) != mset.end()) ? "in": "not in") << std::endl;
	std::cout << " ⤷ 5: " << ((easyfind(mset, 5) != mset.end()) ? "in": "not in") << std::endl;
	
	std::cout << std::endl << BRED << "map" << std::endl << R << "⤷ " << has_find_prototype< std::map<int, int> >() << std::endl;
	std::cout << map << std::endl;
	std::cout << " ⤷ 2: " << ((easyfind(map, 2) != map.end()) ? "in": "not in") << std::endl;
	std::cout << " ⤷ 5: " << ((easyfind(map, 5) != map.end()) ? "in": "not in") << std::endl;
	

	std::cout << std::endl << BRED << "multimap" << std::endl << R << "⤷ " << has_find_prototype< std::multimap<int, int> >() << std::endl;
	std::cout << mmap << std::endl;
	std::cout << " ⤷ 2: " << ((easyfind(mmap, 2) != mmap.end()) ? "in": "not in") << std::endl;
	std::cout << " ⤷ 5: " << ((easyfind(mmap, 5) != mmap.end()) ? "in": "not in") << std::endl;
	
std::cout << BRED << "====================================================================" << R << std::endl << std::endl;
}

void	test_adapativeContainers()
{
	
	std::cout << BGREEN << "====================== Adaptative Containers =======================" << R << std::endl;
	std::stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
	
	std::stack<int> queue;
    queue.push(1);
    queue.push(2);
    queue.push(3);


	std::cout << std::endl << BGREEN << "stack" << std::endl << R << "⤷ " << has_find_prototype< std::stack<int> >() << std::endl;
	std::cout << stack << std::endl;
	std::cout << " ⤷ 2: " << ((easyfind(stack, 2) != NULL) ? "in": "not in") << std::endl;
	std::cout << " ⤷ 5: " << ((easyfind(stack, 5) != NULL) ? "in": "not in") << std::endl;
	
	std::cout << std::endl << BGREEN << "queue" << std::endl << R << "⤷ " << has_find_prototype< std::queue<int> >() << std::endl;
	std::cout << queue << std::endl;
	std::cout << " ⤷ 2: " << ((easyfind(queue, 2) != NULL) ? "in": "not in") << std::endl;
	std::cout << " ⤷ 5: " << ((easyfind(queue, 5) != NULL) ? "in": "not in") << std::endl;
	
	std::cout << BGREEN << "====================================================================" << R << std::endl;
}


int main(void)
{
	test_sequenceContainers();
	test_associativeContainers();
	test_adapativeContainers();

	return (0);
}