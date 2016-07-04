#include <iostream>

void foo(const int &value)
{
    value = 6;
}

int main(int argc, const char *argv[])
{
    int value = 5;
    std::cout << value << std::endl;

    // demo2.cpp:5:11: error: cannot assign to variable 'value' with const-qualified type 'const int &'
    foo(value);
    std::cout << value << std::endl;

    return 0;
}
