#include <iostream>

void doSomething(unsigned int x)
{
    std::cout << x << std::endl;
}

int main(int argc, const char *argv[])
{
	signed short x;
    std::cout << "Please input a num (ex, -1): ";
    std::cin >> x;	
    doSomething(x);

	return 0;
}
