// Copyright [2016] <Vex Woo>

#include <iostream>

template <class SomeType>
void print_array(SomeType arg[], int length) {
    for (int n = 0; n < length; ++n) {
        std::cout << arg[n] << ' ';
    }
    std::cout << '\n';
}


int main(int argc, const char *argv[]) {
    int int_array[] = { 1, 2, 3, 4, 5 };
    char chars_array[] = { 'a', 'b', 'c', 'd', 'e' };

    print_array(int_array, 5);
    print_array(chars_array, 5);

    return 0;
}


/*

In the code above, the first parameter (int arg[]) accepts array whose elements
are type of int, whatever its length. For that reason, we have included a second
parameter that tells the function the length of each array that we pass to it as
its first parameter. This allows the for loop that prints out known the range to
iterate in the array passed, without going out of range.


*/
