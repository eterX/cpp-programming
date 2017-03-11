// Copyright[2016] <Vex Woo>

#include <iostream>

class BaseClass {
 public:
    void setLength(double len);
    double getLength(void);

    // This is the constructor
    BaseClass();

    // Single-parameter constructors should be marked explicit.
    explicit BaseClass(double len);

    // This is a destructor
    ~BaseClass();

 private:
    double length;
};


// Member functions definitions including constructor
BaseClass::BaseClass(void) {
    std::cout << "Object is being created.\n";
}

BaseClass::BaseClass(double len) {
    std::cout << "Object is being created.\n";
    length = len;
}

BaseClass::~BaseClass(void) {
    std::cout << "Object is being deleted.\n";
}

void BaseClass::setLength(double len) {
    length = len;
}


double BaseClass::getLength(void) {
    return length;
}

int main(int argc, const char *argv[]) {
    BaseClass bcls;
    BaseClass bcls2(2.2);

    bcls.setLength(1.1);
    std::cout << bcls.getLength() << "\n";
    std::cout << bcls2.getLength() << "\n";
    return 0;
}
