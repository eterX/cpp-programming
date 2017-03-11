#include <iostream>

// Variables declared outside of a block are global variables
int g_x;          // global variable g_x
const int g_y(2); // global variable g_y

int doSomething()
{
	// global variables can be seen and used everywhere in program	
    g_x = 3;
	std::cout << g_y << "\n";
	return 0;
}

int main()
{
    // global variables can be seen everything in program
	g_x = 5;
	std::cout << g_y << "\n";

	return 0;
}
