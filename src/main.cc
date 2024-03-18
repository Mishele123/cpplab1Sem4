
#include "header.h"



int main()
{
	Tree a;
	a.insert(10);
	a.insert(12);
	a.insert(11);
	a.insert(13);
	a.insert(14);
	a.insert(9);
	a.insert(8);
	a.insert(9);
	a.insert(7);

	a.print();

	std::cout << std::endl;

	a.erase(12);

	a.print();

	std::cout << std::endl;
	
	std::cout << a._root->_left->_data << std::endl;
	std::cout << a._root->getLeftTree()->_data << std::endl;

	std::cout << a.contains(9) << std::endl;

	return 0;
}