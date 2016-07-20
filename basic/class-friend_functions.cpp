// Copyright[2016] <Vex Woo>

#include <iostream>

/*

  ## Friend Functions

  A firend function of a class is defined outside that class' scope but it has
  the right to access all private and protected members of the class. Even though
  the prototype for friend functions appear in the class definition, friends are
  not member functions.

  A friend can be a function, function template, or member function,
  or a class or class template, in which case the entire class and all of
  its members are friends.

  To declare a function as a friend of a class, precede the function prototype in
  the class definition with keyword friend as follow.

*/

class BaseClass {
 private:
    double width;
 public:
    friend void getWidth(BaseClass basecls);
    void setWidth(double wid);
};

// Member function definition
void BaseClass::setWidth(double wid) {
    width = wid;
}

// Note: getWidth() is not a member function of any class.
void getWidth(BaseClass basecls) {
    std::cout << basecls.width << std::endl;
}

/*
// error: 'width' is a private member of 'BaseClass'
void copy_getWidth(BaseClass basecls) {
    std::cout << basecls.width << std::endl;
}
*/

int main(int argc, const char *argv[]) {
    BaseClass democls;
    democls.setWidth(11.1);

    // Use friend function to print the width
    getWidth(democls);
    return 0;
}
