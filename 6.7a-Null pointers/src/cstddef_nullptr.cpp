#include <iostream>
#include <cstddef>

void demo(std::nullptr_t *ptr)
{
	if (ptr)
	{
		std::cout << "ptr pointers to a int value" << std::endl;
	}
	else
	{
		std::cout << "ptr is a null pointer" << std::endl;
	}
}

int main(int argc, const char *argv[])
{
	demo(nullptr);
    return 0;
}
