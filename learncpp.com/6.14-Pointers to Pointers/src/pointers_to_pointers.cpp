#include <iostream>


int main(int argc, const char *argv[])
{
	int value = 5;
	int *ptr = &value;
	int **ptrptr = &ptr;

	std::cout << *ptr << '\n';      // dereference pointer to int to get int value

	std::cout << *ptrptr << '\n';
	std::cout << **ptrptr << '\n' ;  // first dereference to get pointer to int, second dereference to get int value

    return 0;
}
