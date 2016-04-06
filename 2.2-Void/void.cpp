#include <iostream>

void foo1()
{
    std::cout << "/Hello World/" << std::endl;
}

int foo2(void)
{
    std::cout << "/Hello Cpp - 001/" << std::endl;
	return 0;
}

int foo3()
{
    std::cout << "/Hello Cpp - 002/" << std::endl;
	return 0;
}

int main(int argc, const char *argv[])
{
	foo1();
    foo2();	
	foo3();
    return 0;
}
