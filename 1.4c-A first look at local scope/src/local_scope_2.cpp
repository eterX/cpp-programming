#include <iostream>

int add(int x, int y)  // x and y are created here
{
    // x and y are visible/usable within this function only.
	return x + y;
}   // x and y are destroyed here


int main(int argc, const char *argv[])
{
    int x = 5;  // x is initialized here
	int y = 6;  // y is initialized here
	// x and y are usable within this function only
	std::cout << add(x, y) << std::endl;  // calls function add()
	return 0;
}  // x and y are destroyed here

