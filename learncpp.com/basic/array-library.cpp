// Copyright [2016] <Vex Woo>

#include <iostream>
#include <array>


int main(int argc, const char *argv[]) {
    std::array <int, 3> int_array = { 1, 2, 3 };
    for (int i = 0; i < int_array.size(); ++i) {
        std::cout << i << ' ';
    }
    return 0;
}
