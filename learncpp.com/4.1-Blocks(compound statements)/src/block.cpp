#include <iostream>

int add(int x, int y)
{ // start a block
    return x + y;
} // end a block

int main(int argc, const char * argv[])
{ // start a block
    // multiple statements
	int value(0);
	std::cout << "3 + 4 = " << add(3, 4) << std::endl;

	return 0;
} // end a block (no semicolon)
