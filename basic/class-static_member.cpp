// Copyright[2016] <Vex Woo>

#include <iostream>

/*

  ## Static member

  We can define class members static using static keyword. When we declare a
  member of a class as static it means no matter how many objects of the class
  are created, there is only one copy of the static member.

  A static member is shared by all objects of the class. All static data is
  initialized to zero when the first object is created, if no other
  initialization is present. We can't put it in the class definition bu
  it can be initialized outside the class as done in the following example
  by redeclaring the static variable, using the scope resolution operator
  [::] to identify which class it belongs to.

*/

class BaseClass {
 public:
    static int i;            // static members
    static int getTimes();   // static members

    BaseClass();
};

int BaseClass::i = 0;

BaseClass::BaseClass() {
    ++i;
    std::cout << i << " times to create a constructor" << std::endl;
}

int BaseClass::getTimes() {
    return i;
}

int main(int argc, const char *argv[]) {
    BaseClass basecls;
    std::cout << "static num: " << basecls.getTimes() << std::endl;

    BaseClass democls;
    std::cout << "static num: " << democls.getTimes() << std::endl;

    return 0;
}
