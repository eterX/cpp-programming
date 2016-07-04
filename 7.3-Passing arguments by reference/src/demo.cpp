#include <iostream>

void foo(int &value)
{
    value = 6;
}


int main(int argc, const char *argv[])
{
    int value = 5;
    std::cout << value << std::endl;
    foo(value);
    std::cout << value << std::endl;

    return 0;
}
