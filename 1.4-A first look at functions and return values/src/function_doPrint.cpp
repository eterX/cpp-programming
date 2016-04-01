#include <iostream>

void doPrint()
{
    std::cout << "In doPrint()" << std::endl;
}


int main(int argc, const char *argv[])
{
    std::cout << "Starting main()" << std::endl;
	doPrint();
	std::cout << "Ending main()" << std::endl;
	return 0;
}
