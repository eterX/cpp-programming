#include <iostream>

int main(int argc, const char *argv[])
{
	int array[5] = {1, 2, 3, 4, 5};
	std::cout << sizeof(array) << "\n";  // Will print sizeof(int) * array length

	int *ptr = array;
	std::cout << sizeof(ptr) << "\n";    // Will print the size of a pointer

	return 0;
}
