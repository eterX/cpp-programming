#include <iostream>

void foo(int *ptr)
{
    *ptr = 6;
}

int main()
{
    int value = 5;

    std::cout << "value = " << value << '\n';
    foo(&value);
    std::cout << "value = " << value << '\n';

    return 0;
}
