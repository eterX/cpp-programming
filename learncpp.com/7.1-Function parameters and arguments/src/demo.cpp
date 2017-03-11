#include <iostream>

void foo(int x, int y)
{
    std::cout << x << " + " << y << " = " << x + y;
}

int main(int argc, const char *argv[])
{
    foo(1, 2);
    return 0;
}
