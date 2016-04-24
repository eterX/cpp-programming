#include <iostream>

// parameter ptr contains a copy of the array's address
void changeArray(int *ptr)
{
	*ptr = 5; // so changing on array element changes the _actual_ array
}

int main(int argc, const char *argv[])
{
	int array[] = {1, 2, 3, 4, 5, 6};
	std::cout << "Element 0 has value: " << array[0] << "\n";

	changeArray(array);

	std::cout << "Element 0 has value: " << array[0] << "\n";

	return 0;
}
