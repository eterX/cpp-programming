#include <iostream>

int main(int argc, const char *argv[])
{
    char mystring[] = "string";
    mystring[1] = 'p';
    std::cout << mystring;

    return 0;
}
