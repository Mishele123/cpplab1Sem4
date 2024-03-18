
#include "header.h"



int main()
{
	Tree a;
	a.insert(10);
	a.insert(9);
	a.insert(8);
	a.insert(9);
	a.insert(7);

	a.print();

	std::cout << std::endl;

	std::cout << a.contains(9) << std::endl;

	return 0;
}