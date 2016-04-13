#include <iostream>

// compile: clang++ --std=c++14 demo.cpp

auto add(int x, int y)
{
    return x + y;
}


int main(int argc, const char * argv[])
{
    int z = add(1, 2);
	std::cout << "1 + 2 = " << z << std::endl;
	return 0;
}
