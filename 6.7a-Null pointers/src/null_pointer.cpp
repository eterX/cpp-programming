#include <iostream>

int main(int argc, const char *argv[])
{
	int *ptr(0);

	if (ptr)
	{ std::cout << "ptr is pointing to a int value."; }
	else
	{ std::cout << "ptr is a null pointer."; }
}
