// Copyright [2016] <Vex Woo>
#include <iostream>


int main(int argc, const char *argv[]) {
    // error: declaration of variable 'i' with type 'auto' requires an initializer
    auto i = 10;
    static auto m = 3.14;
    std::cout << i << std::endl;
    std::cout << m << std::endl;
    return 0;
}
