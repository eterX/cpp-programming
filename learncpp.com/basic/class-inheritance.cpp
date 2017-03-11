// Copyright[2016] <Vex Woo>

#include <iostream>

/*

 ## Class Inheritance

 One of the most important concepts in object-oriented programming is that of
 inheritance. Inheritance allows us to define a class in terms of another class,
 which makes it easier to create and maintain an application. This also provides
 an opportunity to reuse the code functionality and fast implementation here.

 When creating a class, instead of writing completely new data members and
 member functions, the programmer can designate that the new class should
 inherit the members of an existing class. This existing class is called
 the base class, and the new class is referred to as the derived class.

 ## Base & Derived Classes

     class derived-class: access-specifier base-class

*/

class BaseWidthClass {
 protected:
    double width;

 public:
    void setWidth(double wid) { width = wid; }
    double getWidth(void) { return width; }
};

class BaseHeightClass {
 protected:
    double height;

 public:
    void setHeight(double hei) { height = hei; }
    double getHeight(void) { return height; }
};

/*

  ## Access Control and Inheritance

  A derived class can access all the non-private members of its base class.
  Thus base-class members that should not be accessible to the member functions
  of derived classes should be declared private in the base class.

  Access          public      protected     private
  --------        ---------   -----------   ----------
  Same Class      yes         yes           yes
  Derived Class   yes         yes           no
  Outside Class   yes         no            no

  A derived class inherits all base class methods with the following exceptions:

   - Constructors, destructor and copy constructors of the base class.
   - Overloaded operators of the base class.
   - The friend functions of the base class.

*/

/*

  ## Multiple Inheritance

  class derived-class : access baseclassA, access baseclassB, ......

*/

class BaseLengthClass {
 protected:
    double length;

 public:
    void setLength(double len) { length = len; }
    double getLength(void) { return length; }
};

class wSubClass : public BaseWidthClass {};
class whSubClass : public BaseWidthClass, public BaseHeightClass {};
class whlSubClass : public BaseWidthClass, public BaseHeightClass, public BaseLengthClass {};


int main(int argc, const char *argv[]) {
    wSubClass wcls;
    whSubClass whcls;
    whlSubClass whlcls;

    wcls.setWidth(1.1);
    std::cout << "Width : " << wcls.getWidth() << std::endl;

    whcls.setWidth(1.1);
    whcls.setHeight(2.2);
    std::cout << "Width : " << whcls.getWidth() << std::endl;
    std::cout << "Height : " << whcls.getHeight() << std::endl;

    whlcls.setWidth(1.1);
    whlcls.setHeight(2.2);
    whlcls.setLength(3.3);
    std::cout << "Width : " << whlcls.getWidth() << std::endl;
    std::cout << "Height : " << whlcls.getHeight() << std::endl;
    std::cout << "Length : " << whlcls.getLength() << std::endl;
    return 0;
}
