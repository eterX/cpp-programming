#include <iostream>
#include <string>


int main(int argc, const char *argv[])
{
    std::string name;

    std::cout << "Please input a name: ";
    std::getline(std::cin, name);
    std::cout << "Name is " << name << std::endl;
    return 0;
}
