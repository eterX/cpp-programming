// Copyright[2016] <Vex Woo>

#include <iostream>
#include <exception>

/*

  ## C++ Exception Handling

  http://www.tutorialspoint.com/cplusplus/cpp_exceptions_handling.htm

  Exceptions provide a way to transfer control from one part of a program to
  another. C++ exception handling is built upon three keywords:

      try, catch, and throw.

      throw: A program throws an exception when a problem shows up. This is done
             using a throw keyword.

      catch: A program catches an exception with an exception handler at the place
             in a program where you want to handle the problem. The catch keyword
             indicates the catching of an exception.

      try:   A try block identifies a block of code for which particular exceptions
             will be activated. If's followed by one or more catch blocks.


      try {
         // protected code
      } catch (ExceptionName e1) {
         // catch block
      } catch (ExceptionName e2) {
         // catch block
      }

*/

// Define New Exception
struct MyException : public std::exception {
    const char * what() const throw() {
        return "C++ Exception";
    }
};

double division(int a, int b) {
    if (b == 0) {
        throw "Division by zero condition.";
    }

    return (a / b);
}


int main(int argc, const char *argv[]) {
    int x = 3;
    int y = 0;
    double z = 0;

    try {
        z = division(x, y);
    } catch (const char *exc) {
        std::cerr << exc << std::endl;
    }

    try {
        throw MyException();
    } catch (MyException &e) {
        std::cout << e.what() << std::endl;
    } catch (std::exception &e) {
        // Other errors
    }

    return 0;
}
