#include "iter.hpp"

int main(void)
{
	int arri[5] = { 1, 2, 3, 4, 5};
	char s[5] = { 'c', 'h', 'a', 'r', '\0' };
	iter(arri, 5, test);
	iter(s, 5, test);
	iter((char *)NULL, 5, test);
}