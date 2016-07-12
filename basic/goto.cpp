// Copyright[2016] <Vex Woo>

#include <iostream>


int main(int argc, const char *argv[]) {
    int i;

goto_label:
    std::cout << "Please input a number (n > 5, exit): ";
    std::cin >> i;
    std::cout << "[*] number is " << i << std::endl;

    if (i < 5) { goto goto_label; }
    return 0;
}
