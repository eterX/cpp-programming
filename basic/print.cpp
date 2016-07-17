// Copyright[2016] <Vex Woo>

#include <iostream>

template <class SomeType>
void print(std::initializer_list<SomeType> vals) {
    for (auto p=vals.begin(); p != vals.end(); ++p) {
        std::cout << *p << "\n";
    }
}


int main(int argc, const char *argv[]) {
    print({1, 2, 3, 4});
    print({1.1, 2.2, 3.3, 4.4});

    print({'a', 'b', 'c', 'd'});
    print({"aa", "bb", "cc", "dd"});
    return 0;
}


// Cimpiler: g++ --std=c++11 print.cpp
