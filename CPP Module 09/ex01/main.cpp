#include "RPN.hpp"

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (1);
	try
	{
		RPN rpn(argc - 1, &argv[1]);
		rpn.show_result();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
}