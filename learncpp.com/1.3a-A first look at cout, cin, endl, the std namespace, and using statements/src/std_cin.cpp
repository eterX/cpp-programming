#include <iostream>

int main(int argc, char *argv[])
{
	std::cout << "Enter a number: ";  // ask user for a number
	int x = 0;
	std::cin >> x;  // read number from console and store it in x
	std::cout << "You entered " << x << std::endl;
	return 0;
}
