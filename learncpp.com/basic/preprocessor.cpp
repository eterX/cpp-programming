// Copyright[2016] <Vex Woo>

#include <iostream>

/*

  __LINE__    - Integer value representing the current line in the source code file being compiled.
  __FILE__    - A string interal containing the presumed name of the source file being compiled.
  __DATE__    - A string interal in the form "Mmmm dd yyyy" containing the date in which the compilation process began.
  __TIME__    - A string interal in the form "hh:mm:ss" containing the time at which the compliation process began.
  __cplusplus - An integer value. All C++ compilers have this constant defined to some value. Its value depends on the version of the standard supported by the compiler:

                - 199711L: ISO C++ 1998/2003
                - 201103L: ISO C++ 2011

                Non conforming compilers define this constant as some value at most five digits long. Note that many compilers are not fully conforming and thus will have this constant defined as neither of the values above.
                

 */

int main(int argc, const char* argv[]) {
    std::cout << "This is the line number " << __LINE__;
    std::cout << " of file " << __FILE__ << ".\n";
    std::cout << "Its compilation began " << __DATE__;
    std::cout << " at " << __TIME__ << ".\n";
    std::cout << "The compiler gives a __cplusplus value of " << __cplusplus;
    return 0;
}


// http://www.cplusplus.com/doc/tutorial/preprocessor/
