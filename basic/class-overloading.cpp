// Copyright[2016] <Vex Woo>

#include <iostream>

/*

  ## C++ Overloading (Operator and Function)

  C++ allows you to specify more than one definition for a function name or
  an operator in the same scope, which is called function overloading and
  operator overloading respectively.

  An overloaded declaration is a declaration that had been declared with the
  same name as a previously declared declaration in the same scope, except
  that both declarations have different arguments and obviously different
  definition (implementation).

  When you call an overloaded function or operator, the compiler determines
  the most appropriate definition to use by comparing the argument types
  you used to call the function or operator with the parameter types specified
  in the definitions. The process of selecting the most appropriate overloaded
  function or operator is called overload resolution.

*/

class printClass {
 public:
    void print(int i) {
        std::cout << "Printing int : " << i << std::endl;
    }

    void print(double d) {
        std::cout << "Printing double : " << d << std::endl;
    }

    void print(char *c) {
        std::cout << "Printing character : " << c << std::endl;
    }
};

/*

  ## Operators overloading in C++

  You can redefine or overload most of the built-in operators available in C++.
  Thus a programmer can use operators with user-defined types as well.

*/

class operatorCls {
 private:
    double width;

 public:
    operatorCls() {}
    explicit operatorCls(double wid) : width(wid) {}

    operatorCls operator+ (const operatorCls &op1) {
        operatorCls op;

        op.width = op1.width + this->width;
        return op;
    }

    double getWidth() { return width; }
};


int main(int argc, const char *argv[]) {
    char str[] = "Hello World";
    printClass democls;
    democls.print(1.1);
    democls.print(1);
    democls.print(str);

    operatorCls op;
    operatorCls op1(1.1);
    operatorCls op2(2.2);

    op = op1 + op2;
    std::cout << "Width : " << op.getWidth() << std::endl;

    return 0;
}
