#include <iostream>

void demo(int x, int y=10);

// void demo(int x, int y=10)  // redefinition of default argument
void demo(int x, int y)
{
    std::cout << " x = " << x << " y = " << y << std::endl;
}

void printValues(int x=1, int y=2, int z=3)
{
    std::cout << " x = " << x << " y = " << y << " z = " << z << std::endl;
}

int main(int argc, const char *argv[])
{

    demo(1);
    demo(1, 2);

    printValues(4, 5, 6);

    // printValues(4, 5, );  // expected expression
    printValues(4, 5);

    // printValues(4, , );   // expected expression
    printValues(4);

    return 0;
}
