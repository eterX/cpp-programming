#include <iostream>

int main(int argc, const char *argv[])
{
    int value = 5;
	int *ptr = &value;   // initialize ptr with address of variable value;

	std::cout << &value << '\n';    // print the address of variable value
	std::cout << ptr << '\n';       // print the address that ptr is holding

	return 0;
}
