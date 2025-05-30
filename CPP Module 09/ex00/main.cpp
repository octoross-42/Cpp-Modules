#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "usage: ./btc <file>" << std::endl;
		return (1);
	}
	try
	{
		BitcoinExchange	bitcoin_exchange;
		int i = 1;
		while (i < argc)
			bitcoin_exchange.input(argv[i ++]);
		return (0);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
}