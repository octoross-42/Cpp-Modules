#include "PmergeMe.hpp"


double getRealTime(void)
{
    timespec ts;
    if (clock_gettime(CLOCK_MONOTONIC, &ts) == -1)
		throw std::runtime_error("Couldnt get time");
    return (ts.tv_sec * 1000.0 + ts.tv_nsec / 1000000.0);
}

void	update_time(double *time_real)
{
	*time_real = getRealTime();
}

void	print_time(double *time_real)
{
	std::cout << B << (double)(getRealTime() - *time_real) << " ms" << R << std::endl;
}


int	main(int argc, char **argv)
{
	if (argc < 2)
		return (1);
	try
	{
		std::list<int> list;
		int i = 1;
		int j, k;
		while (i < argc)
		{
			j = 0;
			while (argv[i][j])
			{
				k = 0;
				while (std::isspace(argv[i][j]))
					j ++;
				k = j;
				while (argv[i][j] && !std::isspace(argv[i][j]))
					j ++;
				if (j == k)
					break;
				list.push_back(typeOfString<int>(std::string(argv[i]).substr(k, j - k), "int"));
			}
			i ++;
		}
		std::cout << B << "Before:\t\t" << R;
		std::list<int>::iterator it = list.begin();
		while (it != list.end())
		{
			std::cout << *it;
			i ++;
			if (it != list.end())
				std::cout << " ";
			it ++;
		}
		std::cout << std::endl;

		std::list<int> sorted = list;
		sorted.sort();
		std::cout << B << "After:\t\t" << R;
		it = sorted.begin();
		while (it != sorted.end())
		{
			std::cout << *it;
			i ++;
			if (it != sorted.end())
				std::cout << " ";
			it ++;
		}
		std::cout << std::endl;

		double time_real;
		
		update_time(&time_real);
		mergeWithVector(list);
		std::cout << "Time to process a range of " << B << list.size() << R << " elmts with std::" << B << "vector" << R << "<int> : ";
		print_time(&time_real);
		
		
		update_time(&time_real);
		mergeWithDeque(list);
		std::cout << "Time to process a range of " << B << list.size() << R << " elmts with std::" << B << "deque" << R << "<int> : ";
		print_time(&time_real);

	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
}