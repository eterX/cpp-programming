#include <iostream>

int main(int argc, const char *argv[])
{
	int *value = new (std::nothrow)int;

	if (!value)
	{
		std::cout << "Could not allocate memory";
		exit(1);
	}
	return 0;
}
