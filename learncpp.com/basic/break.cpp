// Copyright[2016] <Vex Woo>

#include <iostream>


int main(int argc, const char *argv[]) {
    for (int i = 0; i < 10; ++i) {
        if (i == 2) { break; }
        std::cout << i << std::endl;
    }
    return 0;
}
