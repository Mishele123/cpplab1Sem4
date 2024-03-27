
#include "header.h"



int main()
{
	Tree tree;

    std::cout << "Average time to fill tree with 1000 elements: " << tree.measureFillTime(1000) << std::endl;
    std::cout << "Average time to fill tree with 10000 elements: " << tree.measureFillTime(10000) << std::endl;
    std::cout << "Average time to fill tree with 100000 elements: " << tree.measureFillTime(100000) << std::endl;

    std::cout << "Average time to search in tree with 1000 elements: " << tree.measureSearchTime(1000) << std::endl;
    std::cout << "Average time to search in tree with 10000 elements: " << tree.measureSearchTime(10000) << std::endl;
    std::cout << "Average time to search in tree with 100000 elements: " << tree.measureSearchTime(100000) << std::endl;

    std::cout << "Average time to insert and delete in tree with 1000 elements: " << tree.measureInsertEraseTime(1000) << std::endl;
    std::cout << "Average time to insert and delete in tree with 10000 elements: " << tree.measureInsertEraseTime(10000) << std::endl;
    std::cout << "Average time to insert and delete in tree with 100000 elements: " << tree.measureInsertEraseTime(100000) << std::endl;

    //Vector
    std::cout << "Average time to fill vector with 1000 elements: " << measureFillTimeVector(1000) << std::endl;
    std::cout << "Average time to fill vector with 10000 elements: " << measureFillTimeVector(10000) << std::endl;
    std::cout << "Average time to fill vector with 100000 elements: " << measureFillTimeVector(100000) << std::endl;

    std::cout << "Average time to search in vector with 1000 elements: " << measureSearchTimeVector(1000) << std::endl;
    std::cout << "Average time to search in vector with 10000 elements: " << measureSearchTimeVector(10000) << std::endl;
    std::cout << "Average time to search in vector with 100000 elements: " << measureSearchTimeVector(100000) << std::endl;

    std::cout << "Average time to insert and delete in vector with 1000 elements: " << measureInsertEraseVector(1000) << std::endl;
    std::cout << "Average time to insert and delete in vector with 10000 elements: " << measureInsertEraseVector(10000) << std::endl;
    std::cout << "Average time to insert and delete in vector with 100000 elements: " << measureInsertEraseVector(100000) << std::endl;

	return 0;
}