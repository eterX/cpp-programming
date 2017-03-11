#include <iostream>

void printSize(int array[])
{
    std::cout << sizeof(array) << "\n";   // prints the size of a pointer, not the size of the array!
}

int main(int argc, const char * argv[])
{
    int array[] = {1, 1, 2, 3, 5, 8, 13, 21};
	std::cout << sizeof(array) << "\n";   // will print the size of the array
	printSize(array);

	return 0;
}
