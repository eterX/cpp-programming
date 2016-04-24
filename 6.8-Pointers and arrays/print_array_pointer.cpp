#include <iostream>

int main(int argc, const char *argv[])
{
    int array[5] = {1, 2, 3, 4, 5};

	// print the value of the array variable
	std::cout << "The array has address: " << array << "\n";

	// print address of the array elements
	std::cout << "Element 0 has address: " << &array[0] << "\n";

	return 0;
}
