// Copyright[2016] <Vex Woo>

#include <iostream>

/*

  ## Polymorphism

  The word polymorphism means having many forms. Typically, polymorphism occurs
  when there is a hierarchy of classes and they are related by inheritance.

  C++ polymorphism means that a call to a member function will cause a different
  function to be executed depending on the type of object that invokes the function.


*/

class Shape {
 protected:
    int width, height;

 public:
     explicit Shape(int a = 0, int b = 0) {
        width = a;
        height = b;
    }

    virtual int area() {
        std::cout << "Parent class area " << std::endl;
        return 0;
    }
};

class Rectange: public Shape {
 public:
    explicit Rectange(int a = 0, int b = 0) : Shape(a, b) { }
    int area() {
        std::cout << "Rectange class area " << std::endl;
        return (width * height);
    }
};

class Triangle: public Shape {
 public:
    explicit Triangle(int a = 0, int b = 0) : Shape(a, b) { }
    int area() {
        std::cout << "Triangle class area " << std::endl;
        return (width * height) / 2;
    }
};

/*

  The reason for the incorrect output is that the call of the function area() is
  being set once by the compiler as the version defined in the base class. This
  is called static resolution of the function call, or static linkage  - the
  function call is fixed before the program is executed.

    - static linkage
    - early binding

  But now, let's make a slight modification in our program and precede the
  declaration of area() in the Shape class with the keyword virtual so that
  it looks like this:

  As you can see, each of the child classes has a separate implementation
  for the function area(). This is how polymorphism is generally used.
  You have different classes with a function of the same name, and even
  the same parameters, but with different implementations.

    - dynamic linkage
    - last binding

*/

int main(int argc, const char *argv[]) {
    Shape *pshape;
    Rectange rec(10, 7);
    Triangle tri(10, 5);

    // store the address of Rectangle
    pshape = &rec;
    // call rectangle area
    pshape->area();

    pshape = &tri;
    pshape->area();

    return 0;
}
