#include <iostream>

int main(int argc, const char *argv[])
{
	int *ptr = new int(5);   // use direct initialization
	std::cout << ptr << "\n";
	std::cout << *ptr << "\n";
	return 0;
}
