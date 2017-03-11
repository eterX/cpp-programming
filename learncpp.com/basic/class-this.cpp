// Copyright[2016] <Vex Woo>

#include <iostream>

/*
  ## this pointer

  Every object in C++ has access to its own address through an important pointer
  called this pointer. The this pointer is an implicit parameter to all member functions.
  Therefore, inside a member function, this may be used to refer to the invoking object.

  Friend functions do not have a this pointer, because friends are not members of a class.

*/


class BaseClass {
 private:
  double length;
  double width;
  double height;

 public:
     ~BaseClass() { std::cout << "Destructor called" << std::endl; }
     explicit BaseClass(double l = 1.1, double w = 2.2, double h = 3.3) : length(l), width(w), height(h) {
         std::cout << "Constructor with parameters called" << std::endl;
     }

     void print() {
       std::cout << "Length: " << this->length << std::endl;
       std::cout << "Width:  " << this->width << std::endl;
       std::cout << "Height: " << this->height << std::endl;
     }
};


int main(int argc, const char *argv[]) {
    BaseClass democls(1.2, 2.3, 3.4);

    // compile: g++ --std=c++11 class-this.cpp
    // BaseClass democls { 1.2, 2.3, 3.4 };

    BaseClass copycls;

    democls.print();
    copycls.print();
    return 0;
}
