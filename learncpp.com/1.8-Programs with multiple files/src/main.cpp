#include <iostream>

// compile: g++ main.cpp add.cpp -o demoprog

int add(int, int);

int main(int argc, const char *argv[])
{
    std::cout << add(2, 3) << std::endl;
	return 0;
}
