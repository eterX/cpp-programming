// Copyright[2016] <Vex Woo>

#include <iostream>
#include <fstream>

int main(int argc, const char *argv[]) {
    std::fstream fileobj("example.txt", std::ios::in | std::ios::binary | std::ios::ate);
    std::streampos size;
    char *buffer;

    if (fileobj.is_open()) {
        size = fileobj.tellg();
        buffer = new char[size];
        fileobj.seekg(0, std::ios::beg);
        fileobj.read(buffer, size);
        std::cout << buffer << std::endl;
        fileobj.close();

        delete[] buffer;
    }
    return 0;
}
