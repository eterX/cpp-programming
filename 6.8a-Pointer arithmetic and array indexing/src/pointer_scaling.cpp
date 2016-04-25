#include <iostream>

int main(int argc, const char *argv[])
{
	int integer = 7;
	int *ptr_integer = &integer;

	short short_int = 7;
	short *ptr_short = &short_int;

	std::cout << "int pointer arithmetic" << "\n";
	std::cout << ptr_integer << "\n";
	std::cout << ptr_integer + 1 << "\n";
	std::cout << ptr_integer + 2 << "\n";
	std::cout << ptr_integer + 3 << "\n";

	std::cout << "short pointer arithmetic" << "\n";
	std::cout << ptr_short << "\n";
	std::cout << ptr_short + 1 << "\n";
	std::cout << ptr_short + 2 << "\n";
	std::cout << ptr_short + 3 << "\n";

	return 0;
}
