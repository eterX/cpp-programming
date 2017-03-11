#include <iostream>

int main(int argc, const char *argv[])
{
	int value = 5;
	int *ptr = &value;
	*ptr = 6;

	std::cout << ptr << "\n";
	std::cout << *ptr << "\n";
    return 0;
}
