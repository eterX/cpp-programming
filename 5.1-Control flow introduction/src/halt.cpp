#include <iostream>
#include <cstdlib>    // needed for exit()

int main(int argc, const char * argv[])
{
    std::cout << 1;
	exit(0);         // terminate and return 0 to operating system

	// The following statements never execute
	std::cout << 2;
	return 0;
}
