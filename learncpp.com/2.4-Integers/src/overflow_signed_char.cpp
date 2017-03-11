#include <iostream>

int main(int argc, const char *argv[])
{
    signed char c = 0xFF;
	std::cout << "char is " << c << std::endl;
	c = c + 1;
	std::cout << "char is " << c << std::endl;
    return 0;
}

