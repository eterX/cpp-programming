// Copyright[2016] <Vex Woo>

#include <iostream>

/*

  ## class access modifiers

  Data hiding is one of the important features of Object Oriented Programming
  which allows preventing the functions of a program to access directly the
  internel representation of a class type.

  The access restriction to the class members is specified by the labeled:
      public
      private
      protected


class Base {
 public:
     // public members go here

 protected:
     // protected members go there

 private:
     // private members go here

};

*/

/*
### The public members

A public member is accessible from anywhere outside the class but within a program.
You can set and get the value of public variables without any member function as
shown in the following example.

*/

class BaseClass {
 protected:
    double breadth;
};

/*
### The private members

A private member variable or function cannot be accessed, or even viewed from outside
the class. Only the class and friend function can access private members.

By default all the members of a class would be private, for example in the following class width is a private member,
which means util you label a member, it woll be assumed a private member:

*/

/*
### The protected members

A protected member variable or function is very similar to a private member but
it provided one additional benefit that they can accessed in child classes which
are called derived classes.

*/

class SubClass:BaseClass {
 private:
  double length;
  double width;

 public:
    void setLength(double len) { length = len; }
    double getLength(void) { return length; }

    void setWidth(double wid) { width = wid; }
    double getWidth(void) { return width; }

    void setBreadth(double bre) { breadth = bre; }
    double getBreadth(void) { return breadth; }
};

int main(int argc, const char *argv[]) {
    SubClass demosubcls;

    demosubcls.setLength(1.1);
    demosubcls.setWidth(2.2);
    demosubcls.setBreadth(3.3);

    std::cout << demosubcls.getBreadth() << "\n";

    return 0;
}
