#include <iostream>

int main(int argc, const char *argv[])
{
	int *ptr = new int(5);
	delete ptr;
	ptr = nullptr;
	return 0;
}
