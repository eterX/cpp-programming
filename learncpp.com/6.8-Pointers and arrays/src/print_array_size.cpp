#include <iostream>

void prtArray(int *array)
{
	std::cout << sizeof(array) << "\n";
}


int main(int argc, const char *argv[])
{
	int array[] = {1, 2, 3, 4, 5};
	std::cout << sizeof(array) << "\n";
	prtArray(array);
	return 0;
}
