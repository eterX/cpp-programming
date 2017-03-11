// Copyright[2016] <Vex Woo>

#include <iostream>


/*

The constructor for this class could be defined, as usual, as:

    Rectangle::Rectangle(int x, int y) { width=x; height=y }

But it could also be defined using [member initialization] as:

    Rectangle::Rectangle(int x, int y) : width(x) { height = y; }

Or even:

    Rectangle::Rectangle(int x, int y) : width(x), height(y) { }
*/

class Rectangle {
    int width, height;

 public:
    Rectangle();
    Rectangle(int x, int y) : width(x), height(y) {}
    void set_values(int x, int y);
    void get_values() {
        std::cout << "Width: " << width << std::endl;
        std::cout << "Height: " << height << std::endl;
    }
};


void Rectangle::set_values(int x, int y) {
    width = x;
    height = y;
}

int main(int argc, const char *argv[]) {
    Rectangle rect = {1, 2};
    rect.get_values();
    rect.set_values(3, 4);
    rect.get_values();
    return 0;
}

// Compile: g++ --std=c++11 class-member_initialization.cpp
