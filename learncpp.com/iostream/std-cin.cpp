#include <iostream>

/*  Basic Input / Output
    cin  - standard input stream
    cout - standard output stream
    cerr - standard error (output) stream
    clog - standard logging (output) stream
 */

int main(int argc, const char *argv[])
{
    int age;

    std::cout << "Please input a age: ";
    std::cin >> age;

    std::cout << "Age is " << age << std::endl;
    return 0;
}
