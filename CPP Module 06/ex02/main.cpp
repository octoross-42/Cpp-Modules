#include "Base.hpp"

Base * generate(void)
{
	int i = rand() % 3;
	if (!i)
		return (new A);
	if (i == 1)
		return (new B);
	return (new C);	
}

void identify(Base* p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
}

void identify(Base& p)
{
	try
	{
		dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		return ;
	}
	catch (std::exception &e) {}
	try
	{
		dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
		return ;
	}
	catch (std::exception &e) {}
	try
	{
		dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
		return ;
	}
	catch (std::exception &e) {}

}


int	main(int argc, char **argv)
{
	if (argc < 2)
		return (1);

	try
	{
		srand(time(NULL));
		Base *b;
		size_t i = 0;
		while (i < typeOfString<unsigned int>(argv[1], "unsigned int"))
		{
			b = generate();
			std::cout << "pointeur: ";
			identify(b);
			std::cout << "reference: ";
			identify(*b);
			std::cout << std::endl;
			delete b;
			i ++;
		}
		return (0);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
	
}