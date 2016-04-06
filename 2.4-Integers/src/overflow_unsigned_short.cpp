#include <iostream>

int main(int argc, const char *argv[])
{
    unsigned short x = 65535;
	std::cout << "x is : " << x << std::endl;
	x = x + 1;
	std::cout << "x is : " << x << std::endl;

    return 0;
}
