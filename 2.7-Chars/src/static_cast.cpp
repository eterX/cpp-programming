#include <iostream>

int main(int argc, const char *argv[])
{
    char ch(97);

	std::cout << ch << std::endl;
	std::cout << static_cast<int>(ch) << std::endl;
	std::cout << ch << std::endl;
    return 0;
}
