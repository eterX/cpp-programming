// Copyright[2016] <Vex Woo>

#include <iostream>

/*

  ## Copy constructor

  The copy constructor is a constructor which creates an object by initializing
  it with an object of the same class, which has been created previously.
  The copy constructor is used to:

   - Initialize one object from another of the same type
   - Copy an object to pass it as an argument to a function.
   - Copy an object to return it from a function.

   classname (const classname &obj) {
       // body of constructor
   }

*/


class BaseClass {
 private:
    int id;
 public:
    BaseClass();                       // constructor
    explicit BaseClass(int id);        // constructor with parameters
    BaseClass(const BaseClass &obj);   // copy constructor
    ~BaseClass();                      // destructor

    int getid(void);
};


BaseClass::BaseClass() {
    std::cout << "constructor: create a object" << std::endl;
}


BaseClass::BaseClass(int id) : id(id) {
    std::cout << "constructor: with a parameter" << std::endl;
}

BaseClass::BaseClass(const BaseClass &obj) {
    id = obj.id;
    std::cout << "copy constructor: id = " << id << std::endl;
}

BaseClass::~BaseClass() {
    std::cout << "destructor: delete a object" << std::endl;
}

int BaseClass::getid(void) {
    return id;
}

int main(int argc, const char *argv[]) {
    BaseClass basecls(10);
    BaseClass copycls = basecls;
    std::cout << "id = " << basecls.getid() << std::endl;
    return 0;
}
