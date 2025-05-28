#include "MutantStack.hpp"

void	test_mstack_construction(void)
{
	std::cout << BBLUE << "====================== TEST CONSTRUCORS ======================================" << R << std::endl;

	MutantStack<int> mstack1;
	mstack1.push(1);
	mstack1.push(2);
	mstack1.push(5);
	std::cout << BBLUE << "First stack<int>: " << R << mstack1 << std::endl;

	MutantStack<std::string> mstack2;
	mstack2.push("lalali");
	mstack2.push("lalala");
	mstack2.push("haha");
	std::cout << BBLUE << "First stack<std::string>: " << R << mstack2 << std::endl;

	MutantStack<int> mstack3;
	mstack3.push(7);
	std::cout << BBLUE << "Third stack<int>: " << R << mstack3 << std::endl;

	MutantStack<int> mstack4(mstack3);
	std::cout << std::endl << BBLUE << "COPY (Fourth stack<int> copy of Third): " << R << mstack4 << std::endl;

	mstack4 = mstack1;
	std::cout << BBLUE << "OPERATOR = (Fourth stack<int> = First): " << R << mstack4 << std::endl;

	std::cout << BBLUE << "==============================================================================" << R << std::endl << std::endl;
}

void	test_access()
{
	std::cout << BCYAN << "====================== TEST ACCESS ===========================================" << R << std::endl;

	MutantStack<int> mstack;
	std::cout << BCYAN << "Empty Stack<int>: " << R << mstack << (mstack.empty() ? " is empty": " isnt empty") << std::endl;
	
	mstack.push(1);
	mstack.push(42);
	mstack.push(17);
	mstack.push(3);
	std::cout << BCYAN << "PUSH (1, 42, 17, 3): " << R << mstack << (mstack.empty() ? " is empty": " isnt empty") << std::endl;

	std::cout << std::endl << BCYAN << "TOP: " << R << mstack.top() << std::endl;
	std::cout << BCYAN << "SIZE: " << R << mstack.size() << std::endl;
	mstack.pop();
	std::cout << BCYAN << "POP: " << R << mstack << std::endl;
	std::cout << BCYAN << "TOP: " << R << mstack.top() << std::endl;
	std::cout << BCYAN << "SIZE: " << R << mstack.size() << std::endl;


	std::cout << BCYAN << "==============================================================================" << R << std::endl << std::endl;

}

void	test_iterator(void)
{
	
	std::cout << BGREEN << "====================== TEST ITERATOR =========================================" << R << std::endl;

	MutantStack<int> mstack;
	mstack.push(1);
	mstack.push(42);
	mstack.push(17);
	mstack.push(3);
	
	std::cout << BGREEN << "stack: " << R << mstack << std::endl << std::endl;
	std::cout << BGREEN << "BEGIN: " << R << *mstack.begin() << std::endl;
	std::cout << BGREEN << "RBEGIN: " << R << *mstack.rbegin() << std::endl;

	std::cout << std::endl << BGREEN << "CONST LOOP from begin to end:" << R << std::endl;
	MutantStack<int>::const_iterator const_it = mstack.begin();
	while (const_it != mstack.end())
		std::cout << " · " << *(const_it ++) << std::endl;
	
	
	std::cout << BGREEN << "LOOP with +1 to every elments from begin to end:" << R << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	while (it != mstack.end())
	{
		*it = *it + 1;
		std::cout << " · " << *(it++) << std::endl;
	}
	std::cout << BGREEN << "  ⤷ RESULT stack: " << R << mstack << std::endl << std::endl;

	std::cout << std::endl << BGREEN << "CONST LOOP from rbegin to rend:" << R << std::endl;
	MutantStack<int>::const_reverse_iterator const_rit = mstack.rbegin();
	while (const_rit != mstack.rend())
		std::cout << " · " << *(const_rit ++) << std::endl;

	std::cout << std::endl << BGREEN << "LOOP with everythig set to 42 from rbegin to rend:" << R << std::endl;
	MutantStack<int>::reverse_iterator rit = mstack.rbegin();
	while (rit != mstack.rend())
	{
		*rit = 42;
		std::cout << " · " << *(rit++) << std::endl;
	}
	std::cout << BGREEN << "  ⤷ RESULT stack: " << R << mstack << std::endl << std::endl;
	std::cout << BGREEN << "==============================================================================" << R << std::endl << std::endl;
}

int	main(void)
{
	test_mstack_construction();
	test_access();
	test_iterator();
	return (0);
}