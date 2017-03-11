#include <iostream>

// returns true if x and y are equal, false otherwise
bool isEqual(int x, int y)
{
    return (x == y); // operator == returns true if x equals y, and false otherwise
}

int main(int argc, const char *argv[])
{
    std::cout << "Enter an integer: ";
	int x;
	std::cin >> x;

	std::cout << "Enter another integer: ";
	int y;
	std::cin >> y;

	bool equal = isEqual(x, y);
	if (equal)
	    std::cout << x << " and " << y << " are equal" << std::endl;
    else
		std::cout << x << " and " << y << " are not equal" << std::endl;

    return 0;	
}
