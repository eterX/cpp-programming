// Copyright[2016] <Vex Woo>

#include <iostream>
#include <string>


int main(int argc, const char *argv[]) {
    std::string command("system");

    // for ( declaration : range ) statement;

    for (char c : command) {
        std::cout << "[" << c << "]";
    }


    // auto - make use of type deduction for the type of the elements
    for (auto c : command) {
        std::cout << "[" << c << "]";
    }
    return 0;
}

// compile: g++ -std=c++11 for_iterator.cpp
