#include <iostream>

void printA()
{
    std::cout << "A" << std::endl;
}

void printB()
{
    std::cout << "B" << std::endl;
}

void printAB()
{
    printA();
	printB();
}

int main(int argc, const char *argv[])
{
    std::cout << "Starting main()" << std::endl;
	printAB();
	std::cout << "Ending main()" << std::endl;
	return 0;
}
