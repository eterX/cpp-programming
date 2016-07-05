#include <iostream>

int add(int x, int y)
{
    return x + y;
}


double add(double x, double y)
{
    return x + y;
}


int main(int argc, const char *argv[])
{
    std::cout << add(1, 2) << std::endl;
    std::cout << add(1.0, 2.2) << std::endl;

    return 0;
}
