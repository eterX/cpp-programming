// Copyright[2016] <Vex Woo>

#include <iostream>

/*
  ## Pointer to C++ classes

  A pointer to a C++ class is done exactly the same way as a pointer to
  a structure and to access members of a pointer to a class you use the
  member access operator [->] operator, just as you do with pointers to
  structures.
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

int main(int argc, const char* argv[]) {
    BaseClass basecls { 1.1, 2.2, 3.3 };
    BaseClass *pbasecls;

    basecls.print();

    // Save the address of first object
    pbasecls = &basecls;

    // Now try to access a member using access operator
    pbasecls->print();

    return 0;
}
