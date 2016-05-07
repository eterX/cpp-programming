#include <iostream>

int main(int argc, const char *argv[])
{
    const int value = 5;
	const int *ptr = &value;
	std::cout << ptr << "\n";
	std::cout << *ptr << "\n";
    return 0;
}
