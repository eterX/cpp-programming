#include <iostream>

int main(int argc, const char *argv[])
{
    char str_demo[20] = "HelloWorld";
	std::cout << "My string is " << str_demo << '\n';
	std::cout << str_demo << " has " << strlen(str_demo) << " letters.\n";
	std::cout << str_demo << " has " << sizeof(str_demo) << " characters in the array.\n";

	return 0;
}
