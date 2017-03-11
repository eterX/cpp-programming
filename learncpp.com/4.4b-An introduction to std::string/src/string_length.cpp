#include <string>
#include <iostream>

int main(int argc, char *argv[])
{
    std::string demo_string;
	std::cout << "Please input a word: ";
	std::cin >> demo_string;
	std::cout << "You have typed: " << demo_string << " - length: " << demo_string.length();
	return 0;
}
