// Copyright[2016] <Vex Woo>

#include <iostream>
#include <fstream>


void filesize(char *filename) {
    std::streampos begin, end;
    std::ifstream fileobj(filename, std::ios::binary);

    if (fileobj.is_open()) {
        begin = fileobj.tellg();
        fileobj.seekg(0, std::ios::end);
        end = fileobj.tellg();

        std::cout << filename << " has [";
        std::cout << (end - begin);
        std::cout << "] bytes" << "\n";
    } else {
        std::cout << "Failed to open " << filename << "\n";
    }
}


int main() {
    char file1[] = "/bin/ls";
    char file2[] = "invalid.txt";
    filesize(file1);
    filesize(file2);
    return 0;
}
