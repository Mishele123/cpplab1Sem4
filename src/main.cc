
#include "header.h"



int main()
{
	Tree a;

	std::cout << a.measureFillTime(100000) << std::endl;
	std::cout << a.measureSearchTime(100000) << std::endl;

	return 0;
}