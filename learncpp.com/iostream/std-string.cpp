#include <iostream>
#include <string>

/*  Basic Input / Output
    cin  - standard input stream
    cout - standard output stream
    cerr - standard error (output) stream
    clog - standard logging (output) stream
 */

int main(int argc, const char *argv[])
{
    std::string name;

    std::cout << "Please input a name: ";
    std::cin >> name;

    // If a name includes a space, pleae try [std-getline.cpp]
    std::cout << "Name is " << name << std::endl;
    return 0;
}
