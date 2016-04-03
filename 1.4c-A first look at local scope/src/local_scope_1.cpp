#include <iostream>

int add(int x, int y)  // x and y are created here
{
    // x and y are visible/usable within this function only.
	return x + y;
}   // x and y are destroyed here


int main(int argc, const char *argv[])
{
    int a = 5;  // a is initialized here
	int b = 6;  // b is initialized here
	// a and b are usable within this function only
	std::cout << add(a, b) << std::endl;  // calls function add() with x=a and y=b
	return 0;
}  // a and b are destroyed here

