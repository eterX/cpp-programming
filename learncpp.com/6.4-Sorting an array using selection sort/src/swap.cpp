#include <iostream>
#include <algorithm>  // for std::swap, use <utility> instead of C++11

int main(int argc, const char * argv[])
{
    int x = 2;
	int y = 4;

	std::cout << "Before swap: x = " << x << ", y = " << y << "\n";
	std::swap(x, y);  // swap the values of x and y
	std::cout << "After  swap: x = " << x << ", y = " << y << "\n";
	return 0;
}

