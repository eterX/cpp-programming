#include <iostream>

int main(int argc, const char *argv[])
{
    char name[255];    // declare array large enough to hold 255 characters
	std::cout << "Enter your name: ";
	std::cin.getline(name, 255);
	std::cout << "Yo entered: " << name << '\n';

	return 0;
}
