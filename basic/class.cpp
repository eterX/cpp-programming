// Copyright[2016] <Vex Woo>

#include <iostream>


class Rectangle {
    int width, height;

 public:
    Rectangle();
    Rectangle(int, int);        // constructor function
    void set_values(int, int);
    void get_values(void);
    int area(void) { return width * height; }
};


void Rectangle::set_values(int x, int y) {
    width = x;
    height = y;
}

void Rectangle::get_values(void) {
    std::cout << "width: " << width << std::endl;
    std::cout << "height: " << height << std::endl;
}
/*
 ## Constructors

 What would happen in the previous example if we called the member function [area]
 before having called [set_values] ? An undetermined result,
 since the members width and height had never been assigned a value.

 In order to avoid that, a class can include a special function called its constructor,
 which is automatically called whenever a new object of this class is created,
 allowing the class to initialize member variables or allocate storage.
 */

Rectangle::Rectangle(int x, int y) {
    width = x;
    height = y;
}

/*

 ## Overloading constructors

 Like any other function, a constructor can also be overloaded with different
 versions taking different parameters: with a different number of parameters
 and/or parameters of different types.
 */

Rectangle::Rectangle() {
    width = 5;
    height = 5;
}


// Rectangle::Rectangle(int x, int y)

int main(int argc, const char* argv[]) {
    Rectangle rect;
    rect.set_values(3, 4);
    std::cout << "area: " << rect.area() << std::endl;

    rect.get_values();
    return 0;
}
