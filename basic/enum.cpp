// Copyright[2016] <Vex Woo>

#include <iostream>

enum colors {
    red,
    yellow,
    green,
    blue
};

void choose(colors c) {
    switch (c) {
        case red:
            std::cout << "color: red" << "\n";
            break;
        case yellow:
            std::cout << "color: yellow" << "\n";
            break;
        case green:
            std::cout << "color: green" << "\n";
            break;
        case blue:
            std::cout << "color: blue" << "\n";
            break;
        default:
            std::cout << "no color here" << "\n";
    }
}
int main(int argc, const char* argv[]) {
    colors c = blue;
    choose(c);
    return 0;
}
