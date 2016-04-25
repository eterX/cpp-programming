#include <iostream>

int main(int argc, const char *argv[])
{
	int array[] = {1, 2, 3, 4, 5};
	char char_ary[] = "Hello";

	std::cout << "Element 0 is at address: " << &array[0] << "\n";
	std::cout << "Element 1 is at address: " << &array[1] << "\n";
	std::cout << "Element 2 is at address: " << &array[2] << "\n";
	std::cout << "Element 3 is at address: " << &array[3] << "\n";

	std::cout << array << "\n";
	std::cout << array + 1 << "\n";
	std::cout << array + 2 << "\n";
	std::cout << array + 3 << "\n";

	std::cout << "Element 0 is at address: " << &char_ary[0] << "\n";
	std::cout << "Element 1 is at address: " << &char_ary[1] << "\n";
	std::cout << "Element 2 is at address: " << &char_ary[2] << "\n";
	std::cout << "Element 3 is at address: " << &char_ary[3] << "\n";
	return 0;
}
