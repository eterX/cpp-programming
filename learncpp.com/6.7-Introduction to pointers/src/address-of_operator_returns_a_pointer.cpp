#include <iostream>

int main(int argc, const char *argv[])
{
    int x(5);
	std::cout << typeid(x).name() << '\n';
    std::cout << typeid(&x).name();	
    return 0;
}
