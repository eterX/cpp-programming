// Copyright[2016] <Vex Woo>

#include <iostream>

// url: http://stackoverflow.com/questions/213121/use-class-or-typename-for-template-parameters
// typename VS class
template <typename SomeType>
SomeType add(SomeType x, SomeType y) {
    SomeType result;
    result = x + y;
    return result;
}


template <class SomeType>
SomeType sub(SomeType x, SomeType y) {
    SomeType result;
    result = x - y;
    return result;
}


template <class X, class Y>
bool is_equal(X a, Y b) {
    return (a == b);
}

int main(int argc, const char *argv[]) {
    std::cout << add<int>(2, 1) << std::endl;
    std::cout << add<double>(2.1, 1.0) << std::endl;

    std::cout << sub<int>(2, 1) << std::endl;
    std::cout << sub<double>(2.1, 1.0) << std::endl;

    // http://stackoverflow.com/questions/8261674/c-bool-returns-0-1-instead-of-true-false
    // http://stackoverflow.com/questions/29383/converting-bool-to-text-in-c
    std::cout << std::boolalpha << is_equal(1, 2) << std::endl;

    return 0;
}
