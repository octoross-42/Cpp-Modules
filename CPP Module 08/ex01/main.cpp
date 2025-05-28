#include "Span.hpp"
#include <sys/time.h>

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
	std::cout << B << "CPU time: " << R << (double)((getCPUTime() - *time_cpu) * 1000000.0) / (double)CLOCKS_PER_SEC << " ms" << std::endl;
	std::cout << B << "Real time: " << R << (double)(getRealTime() - *time_real) << " ms" << std::endl << std::endl;
		
}

void	add_n_number(Span &span, unsigned int n, unsigned int max)
{
	std::vector<int> v;
	v.reserve(n);
	unsigned int i = 0;
	while (i ++ < n)
	{
		if (max > 0)
			v.push_back(std::rand() % max);
		else
			v.push_back(std::rand());
	}
	try {
		span.addNumber(v.begin(), v.end());
	}
	catch (const std::exception &e)
	{
		std::cout << BRED << "Error: " << BR << RED << e.what() << R << std::endl << std::endl;
	}
}

void	test_badAddNumber(void)
{
	std::cout << BRED << "====================== TEST ERROR FULL STORAGE EXPECTED ======================" << R << std::endl;
	Span span(50);
	add_n_number(span, 51, 0);
	std::cout << BRED << "==============================================================================" << R << std::endl << std::endl;
}

void	test_addNumber(void)
{
	std::cout << BBLUE << "====================== TEST ADD NUMBERS ======================================" << R << std::endl;
	
	Span span(2);
	double time_real, time_cpu;

	update_time(&time_real, &time_cpu);
	add_n_number(span, 2, 0);
	std::cout << BBLUE << "Insertion: " << R << 2 << std::endl;
	print_time(&time_real, &time_cpu);
	
	span = Span(2000000);
	update_time(&time_real, &time_cpu);
	add_n_number(span, 2000000, 0);
	std::cout << BBLUE << "Insertion: " << R << 2000000 << std::endl;
	print_time(&time_real, &time_cpu);
	
	std::cout << BBLUE << "==============================================================================" << R << std::endl << std::endl;
	
}

void	test_spans(void)
{
	std::cout << BGREEN << "====================== TEST SPANS ============================================" << R << std::endl;
	
	std::cout << B << "With big, unknown span" << std::endl;
	Span span(500000);
	double time_real, time_cpu;
	add_n_number(span, 500000, 0);

	update_time(&time_real, &time_cpu);
	std::cout << BGREEN << "Shortest Span:" << R << " (after 500000 elmts insertion): " << span.shortestSpan() << std::endl;
	print_time(&time_real, &time_cpu);
	update_time(&time_real, &time_cpu);
	
	std::cout << BGREEN << "Shortest Span:" << R << " (no insertion): " << span.shortestSpan() << std::endl;
	print_time(&time_real, &time_cpu);
	update_time(&time_real, &time_cpu);

	std::cout << BGREEN << "Longest Span:" << R << " (after 500000 elmts insertion): " << span.longestSpan() << std::endl;
	print_time(&time_real, &time_cpu);
	update_time(&time_real, &time_cpu);

	std::cout << BGREEN << "Longest Span:" << R << " (no insertion): " << span.longestSpan() << std::endl;
	print_time(&time_real, &time_cpu);
	std::cout << std::endl;

	span = Span(5);
	add_n_number(span, 5, 20);
	std::cout << B << "With small, random span: " << B << span << R << std::endl;

	update_time(&time_real, &time_cpu);
	std::cout << BGREEN << "Shortest Span:" << R << " (after 5 elmts insertion): " << span.shortestSpan() << std::endl;
	print_time(&time_real, &time_cpu);
	update_time(&time_real, &time_cpu);
	
	std::cout << BGREEN << "Shortest Span:" << R << " (no insertion): " << span.shortestSpan() << std::endl;
	print_time(&time_real, &time_cpu);
	update_time(&time_real, &time_cpu);

	std::cout << BGREEN << "Longest Span:" << R << " (after 5 elmts insertion): " << span.longestSpan() << std::endl;
	print_time(&time_real, &time_cpu);
	update_time(&time_real, &time_cpu);

	std::cout << BGREEN << "Longest Span:" << R << " (no insertion): " << span.longestSpan() << std::endl;
	print_time(&time_real, &time_cpu);
	std::cout << BGREEN << "==============================================================================" << R << std::endl << std::endl;
}

int	main(void)
{
	std::srand(std::time(0));
	std::cout << std::fixed;
	std::cout.precision(10);

	test_badAddNumber();
	test_addNumber();
	test_spans();

}