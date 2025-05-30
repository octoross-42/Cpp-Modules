#include "PMergeMe.hpp"


double getCPUTime(void)
{
    timespec ts;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &ts);
    return (ts.tv_sec * 1000.0 + ts.tv_nsec / 1000000.0);
}

double getRealTime(void)
{
    timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (ts.tv_sec * 1000.0 + ts.tv_nsec / 1000000.0);
}

void	update_time(double *time_real, double *time_cpu)
{
	*time_real = getRealTime();
	*time_cpu = getCPUTime();
}

void	print_time(double *time_real, double *time_cpu)
{
	std::cout << std::endl << B << "\t⤷ CPU time: " << R << (double)((getCPUTime() - *time_cpu) * 1000.0) / (double)CLOCKS_PER_SEC << " ms" << std::endl;
	std::cout << B << "\t⤷ Real time: " << R << (double)(getRealTime() - *time_real) << " ms" << std::endl << std::endl;
}


int	main(int argc, char **argv)
{
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
		std::cout << std::endl << std::endl;

		double time_real, time_cpu;
		
		update_time(&time_real, &time_cpu);
		mergeWithVector(list);
		std::cout << "Time to process a range of " << B << list.size() << R << " elmts with std::vector<int> : ";
		print_time(&time_real, &time_cpu);
		
		
		update_time(&time_real, &time_cpu);
		mergeWithList(list);
		std::cout << "Time to process a range of " << B << list.size() << R << " elmts with std::list<int> : ";
		print_time(&time_real, &time_cpu);

	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
}