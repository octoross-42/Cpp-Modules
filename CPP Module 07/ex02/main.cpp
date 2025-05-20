#include "Array.hpp"

int main(void)
{
	Array<int> a;
	Array<char> b(5);
	Array<int> c(3);
	b[1] = 'a';
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
}