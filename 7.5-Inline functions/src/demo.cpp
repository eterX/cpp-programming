#include <iostream>

inline int min(int x, int y)
{
    return x > y ? y : x;
}

int main(int argc, const char *argv[])
{
    std::cout << min(1, 2) << std::endl;
    std::cout << min(3, 4) << std::endl;
    return 0;
}
