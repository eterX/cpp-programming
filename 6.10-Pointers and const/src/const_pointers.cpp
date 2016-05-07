#include <iostream>

int main(int argc, const char *argv[])
{
    int value = 5;
	int *const ptr1 = &value;
	int * const ptr2 = &value;

	std::cout << ptr1 << "\n";
	std::cout << ptr2 << "\n";

	return 0;
}
