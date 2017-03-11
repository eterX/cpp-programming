// Copyright[2016] <Vex Woo>

#include <iostream>

int operate(int a, int b) {
    return (a * b);
}

double operate(double a, double b) {
    return (a / b);
}

int main(int argc, const char *argv[]) {
    int x = 5, y = 2;
    double m = 5.0, n = 2.0;
    std::cout << operate(x, y) << std::endl;
    std::cout << operate(m, n) << std::endl;
    return 0;
}
