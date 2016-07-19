// Copyright[2016] <Vex Woo>

#include <iostream>

/*

  A member function of a class is a function that has definition or
  its prototype within the class definition like any other variable.
  It operates on any object of the class of which it is a member, and
  has access to all the members of a class for that object.

 */

class Box {
 public:
  double length;
  double breadth;
  double height;

  double getVolume(void) {
      return length * breadth * height;
  }

  void setLength(double len);
  void setBreadth(double bre);
  void setHeight(double hei);
};


/*

  Member functions can be defined within the class definition or separately using
  [scope resolution operator, ::]
  Defining a member function within the class definition declares the function inline,
  even if you do not use the inline specifier. So either you can define getVolume() function as below:

 */

void Box::setLength(double len) { length = len; }

void Box::setBreadth(double bre) { breadth = bre; }

void Box::setHeight(double hei) { height = hei; }
// void Box::setHeight(double hei) : height(hei) { }
// only constructors take base initializers

int main(int argc, const char *argv[]) {
    Box BoxClass;
    BoxClass.setHeight(1.1);
    BoxClass.setBreadth(2.0);
    BoxClass.setLength(3.0);

    std::cout << BoxClass.getVolume() << "\n";
    return 0;
}
